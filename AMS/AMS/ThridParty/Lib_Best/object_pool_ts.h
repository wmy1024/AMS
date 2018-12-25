/**************************************************************************
* �ļ�˵��	��object_pool.h (���߰�ȫ��)
HASH�㷨���ඨ��
* ������	���º�
* ��������	��2010-6-20
* ʹ�÷���	��
��һ����
���轫�����Ķ�����д洢�Ķ�������ΪT�������ö���أ�Ĭ���ڲ��������Ϊ32��
Object_Pool<T> pool_(sz);

�ڶ�����
������Ҫ����alloc������acquire��������ȡһ��������ڴ�ռ������T����
T *obj_ = pool_.alloc();		//ֻ��ȡ����ָ�룬�����ö����캯��
or	T *obj_ = pool_.acquire();		//�Զ���������T�����Ĭ�Ϲ��캯��
(FIFO��LIFO����ö����init����)

��������
������Ҫ����free������release�������ͷŸ�����T�Ķ��󵽶���أ�
ע��ò��������ͷŶ����ڴ�ռ�
free(obj_);						//ֻ�黹���󵽳أ������ö�����������
or  release(obj_);					//�ȵ��ö�����������(FIFO��LIFO����ö����dump����),
Ȼ��黹���󵽳�


����������еĶ����趯̬����������������ʽά����ϵͳ�ڶ���ض�������ʱ˳��
�ͷ��ڴ�ռ�

* �޸��б�	��
2008/6/28
1����ԭ�����ϣ�������Կ��ж�������LIFO��FIFO���ֲ��Զ����ʵ��
2��LIFO��FIFO���ֲ��ԵĶ����Ҫ��������ʵ��initialize()��destory()����������
ϵͳ�ڡ��������͡��������ö���ʱ���Զ����ø÷�������ë���ܵ�����

2008/7/27
1���޸Ĳ�ͳһ����ص��ýӿڣ������������˹淶
2���޸��˲���LIFO��FIFO����ص�ʵ�֣�����ʵ�ַ�����ԭ�ȵ�initialize()��destory()����������
��Ϊ����ʵ��init()��dump()��������
3��LIFO��FIFO���ֲ��ԣ��ڶ���ش���������ʱ��Ϊÿ�����ж����Զ����ù��캯�������ڳ�����ʱ
ֻ�ͷŶ���ռ䣬������ö����������������Ա����ڶ�����ʱ�ǳ�ע�⣬��Ҫ���ڶ������������
���ڴ�ռ��ͷŲ���(��:����ָ����ָ�ڴ�ռ���ͷ�),�����ⷽ�������뽫����ʵ���ڶ����dump������

2008/8/18
1���޸���std::size_t��VC6�±��벻ͨ��������
2��������get_used_objects��get_total_objects��get_empty_objects���������������պ���ͳ��

**************************************************************************/
#ifndef __OBJECT_POOL_THREAD_SAFE_H
#define __OBJECT_POOL_THREAD_SAFE_H
#if (defined _WIN32)||(defined _WIN64)
#pragma warning(disable:4345)
#endif

#include <functional>
#include <new>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include <algorithm>

#include "qcstutils.h"
#include "object_pool.h"


//##ModelId=4C28B0C30078
template <typename T>
class TS_Object_Pool
{
public:
	//##ModelId=4C28B0C3007E
	typedef T element_type;
	//##ModelId=4C28B0C30080
	typedef size_t size_type;

public:
	//##ModelId=4C28B0C301C6
	explicit TS_Object_Pool(const size_type sz = 32) 
		: requested_size(sizeof(T)),
		next_size(sz),
		used_objs(0),
		total_size(0),
		list(0,0)
	{ 
		first = NULL;
		min_alloc_size = lcm<size_type>(sizeof(void *), sizeof(size_type));
	}

	//##ModelId=4C28B0C301C9
	virtual ~TS_Object_Pool() 
	{ 
		PODptr<size_type> iter = list;

		while(iter.valid())
		{
			const PODptr<size_type> next = iter.next();
			delete [](iter.begin());
			iter = next;
		}

		list.invalidate();
		this->first = 0;
		used_objs = 0;
		next_size = total_size;
	}

	//##ModelId=4C28B0C301CA
	virtual element_type * alloc()
	{ 
		mutex.Lock();
		if (first == NULL && alloc_i() == -1)
		{
			mutex.Unlock();
			return NULL;
		}

		void * const ret = first;
		first = nextof(first);
		used_objs++;
		mutex.Unlock();
		return static_cast<element_type *>(ret);
	}

	//##ModelId=4C28B0C301CC
	virtual void free(element_type *& chunk)
	{ 
		mutex.Lock();
		nextof(chunk) = first;
		first = chunk;
		chunk = NULL;
		used_objs--;
		mutex.Unlock();
	}

	//##ModelId=4C28B0C301CF
	virtual element_type * acquire()
	{
		element_type * ret = this->alloc();

		if (ret == 0)
			return ret;

		try { 
			new (ret) element_type(); 
		}
		catch (...) 
		{ 
			this->free(ret); throw; 
		}

		return ret;
	}

	//##ModelId=4C28B0C301D1
	virtual void release(element_type * &chunk)
	{
		chunk->~T();
		this->free(chunk);
	}

	virtual inline void set_object_size(size_type sz = 0)
	{
		if (sz == 0)
			requested_size = sizeof(T);
		else
			requested_size = sz;
	}

	virtual inline size_type get_used_objects(void)
	{
		return used_objs;
	}

	virtual inline size_type get_total_objects(void)
	{
		return total_size;
	}

	virtual inline size_type get_empty_objects(void)
	{
		return (total_size - used_objs);
	}

	virtual inline bool is_valid(element_type * const chunk)
	{
		return true;
	}
protected:
	//##ModelId=4C28B0C301BD
	static inline void * & nextof(void * const ptr)
	{ 
		return *(static_cast<void **>(ptr)); 
	}

	//##ModelId=4C28B0C301C0
	virtual void * segregate(void * block,
		size_type sz, 
		size_type partition_sz,
		void * end_ = 0)
	{
		char * old = static_cast<char *>(block)
			+ ((sz - partition_sz) / partition_sz) * partition_sz;

		nextof(old) = end_;

		if (old == block)
			return block;

		for (char * iter = old - partition_sz; iter != block; old = iter, iter -= partition_sz)
			nextof(iter) = old;

		nextof(block) = old;
		return block;
	}

	virtual int alloc_i(void)
	{
		const size_type partition_size = lcm<size_type>(requested_size, min_alloc_size);
		const size_type POD_size = next_size * partition_size + min_alloc_size + sizeof(size_type);
		char * const ptr = new (std::nothrow) char[POD_size];
		/*total_size += next_size;*/

		if (ptr == NULL)
			return -1;

		total_size += next_size;
		const PODptr<size_type> node(ptr, POD_size);
		next_size <<= 1;
		first = segregate(node.begin(), node.element_size(), partition_size);
		node.next(list);
		list = node;

		return 0;
	}

	//##ModelId=4C28B0C301A0
	size_type requested_size;
	//##ModelId=4C28B0C301A5
	size_type next_size;
	//##ModelId=4C28B0C301AA
	size_type used_objs;
	size_type total_size;
	//##ModelId=4C28B0C301AE
	void *first;
	//##ModelId=4C28B0C301B4
	PODptr<size_type> list;
	//##ModelId=4C28B0C301B9
	size_type min_alloc_size;

	QCMutex mutex;
};

//##ModelId=4C28B0C30066
template<typename T>
class TS_LIFO_Object_Pool : public TS_Object_Pool<T> {
public:
	//##ModelId=4C28B0C3006D
	typedef T element_type;
	//##ModelId=4C28B0C3006F
	typedef size_t size_type;
	enum {
		NORMAL_STATE = 0,
		EXTRA_STATE = 1
	};
public:
	//##ModelId=4C28B0C30174
	explicit TS_LIFO_Object_Pool(const size_type sz = 32, 
								const size_type max_sz = 0) 
	{ 
		this->first = NULL;
		this->next_size = sz;
		extra_objs = 0;
		has_dumped = false;

		if (max_sz == 0 || max_sz <= sz)
			//max_alloc_size = (next_size << 1);
			max_alloc_size = this->next_size;
		else
			max_alloc_size = max_sz;
	}

	virtual ~TS_LIFO_Object_Pool()
	{
		if (!has_dumped)
			dump();
	}

	virtual void dump() 
	{ 
		if (!has_dumped)
		{
			const size_type offset_ = this->min_alloc_size;
			const size_type partition_sz = this->requested_size + offset_;

			PODptr<size_type> iter = this->list;

			while(iter.valid())
			{
				register T *ptr_obj = NULL;

				for (register char * block = iter.begin() + iter.element_size() - partition_sz; 
					block != iter.begin(); block -= partition_sz)
				{
					ptr_obj = reinterpret_cast<T*>(block + offset_);
					ptr_obj->~T();
				}

				ptr_obj = reinterpret_cast<T*>(iter.begin() + offset_);
				ptr_obj->~T();

				const PODptr<size_type> next = iter.next();
				iter = next;
			}

			has_dumped = true;
		}
	}

	virtual inline void set_max_size(size_t sz) 
	{
		if (sz == 0 || sz <= this->next_size)
			max_alloc_size = this->next_size;
		else
			max_alloc_size = sz;
	}

	//##ModelId=4C28B0C30177
	virtual element_type* alloc()
	{
		QCStMutexLocker auto_mutex(&this->mutex);

		if (this->first == NULL && alloc_i() == -1)
			return NULL;

		void** ret = static_cast<void**>(this->first) + 1;
		this->first = this->nextof(this->first);

		if ((this->used_objs == max_alloc_size) && (extra_objs > 0))
			*(ret - 1) = (void*)EXTRA_STATE;
		else
		{
			*(ret - 1) = (void*)NORMAL_STATE;
			this->used_objs++;
		}

		return reinterpret_cast<element_type *>(ret);
	}

	//##ModelId=4C28B0C30179
	virtual void free(element_type * &chunk)
	{
		QCStMutexLocker auto_mutex(&this->mutex);

		void** ptr_ = reinterpret_cast<void**>(chunk) - 1;

		if (*ptr_ == (void*)EXTRA_STATE)
		{
			chunk->~T();
			delete[](reinterpret_cast<char*>(ptr_));
			extra_objs--;
		}
		else
		{
			this->nextof(static_cast<void*>(ptr_)) = this->first;
			this->first = static_cast<void*>(ptr_);
			this->used_objs--;
		}
		chunk = NULL;
	}

	//##ModelId=4C28B0C301CF
	virtual element_type * acquire()
	{
		element_type* chunk = alloc();

		if (chunk == 0)
			return chunk;

		try { 
			chunk->init();
		}
		catch (...) 
		{ 
			this->free(chunk); 
			throw; 
		}

		return chunk;
	}

	//##ModelId=4C28B0C301D1
	virtual void release(element_type * &chunk)
	{
		chunk->dump();
		this->free(chunk);
	}

	virtual inline size_type get_used_objects(void)
	{
		return this->used_objs + extra_objs;
	}

	virtual inline size_type get_total_objects(void)
	{
		return this->total_size + extra_objs;
	}

	virtual inline size_type get_empty_objects(void)
	{
		return (this->total_size - this->used_objs);
	}

	virtual inline bool is_valid(element_type * const chunk)
	{
		void** ptr_ = reinterpret_cast<void**>(chunk) - 1;

		if (*ptr_ == (void*)EXTRA_STATE ||
			*ptr_ == (void*)NORMAL_STATE)
		{
			return false;
		}
		return true;
	}

protected:
	//##ModelId=4C28B0C3016B
	virtual void * segregate(void * block,
		size_type sz, 
		size_type partition_sz,
		void * end_ = 0)
	{
		char * old = static_cast<char *>(block)
			+ ((sz - partition_sz) / partition_sz) * partition_sz;

		register const size_type offset_ = this->min_alloc_size;

		try{
			this->nextof(old) = end_;
			construct(old + offset_);

			if (old == block)
				return block;

			for (char * iter = old - partition_sz; iter != block; old = iter, iter -= partition_sz)
			{
				this->nextof(iter) = old;
				construct(iter + offset_);
			}

			this->nextof(block) = old;
			construct(static_cast<char *>(block) + offset_);
		}
		catch(...)
		{
			delete[] static_cast<char *>(block);
			return NULL;
		}

		return block;
	}

	//##ModelId=4C28B0C30171
	virtual void construct(void * ptr)
	{
		element_type * ret = static_cast<element_type*>(ptr);

		try { 
			new (ret) element_type(); 
		}
		catch (...) 
		{ 
			throw; 
		}
	}

	virtual int alloc_i(void)
	{
		if (this->total_size < max_alloc_size)
		{
			const size_type offset_ = this->min_alloc_size;
			const size_type partition_size = this->requested_size + offset_;
			size_type POD_size = 0;
			if (this->total_size + this->next_size > max_alloc_size)
			{
				POD_size = (max_alloc_size - this->total_size) * partition_size + this->min_alloc_size + sizeof(size_type);
				this->total_size = max_alloc_size;
			}
			else
			{
				POD_size = this->next_size * partition_size + this->min_alloc_size + sizeof(size_type);
				this->total_size += this->next_size;
				this->next_size <<= 1;
			}

			char * const ptr = new (std::nothrow) char[POD_size];
			if (ptr == NULL)
				return -1;

			const PODptr<size_type> node(ptr, POD_size);			
			this->first = segregate(node.begin(), node.element_size(), partition_size);
			node.next(this->list);
			this->list = node;
		}
		else
		{
			const size_type offset_ = this->min_alloc_size;
			const size_type POD_size = this->requested_size + offset_;
			char * const ptr = new (std::nothrow) char[POD_size];

			if (ptr == NULL)
				return -1;

			this->first = ptr;
			construct(ptr + offset_);
			*(static_cast<void**>(this->first)) = NULL;
			extra_objs++;
		}

		return 0;
	}

private:
	bool	  has_dumped;
	size_type max_alloc_size;
	size_type extra_objs;
};

//##ModelId=4C28B0C3003E
template<typename T>
class TS_FIFO_Object_Pool : public TS_Object_Pool<T> {
public:
	//##ModelId=4C28B0C3005F
	typedef T element_type;
	//##ModelId=4C28B0C30061
	typedef size_t size_type;
	enum {
		NORMAL_STATE = 0,
		EXTRA_STATE = 1
	};
public:
	//##ModelId=4C28B0C30162
	explicit TS_FIFO_Object_Pool(const size_type sz = 32, 
								const size_type max_sz = 0) 
	{ 
		this->first = NULL;
		this->next_size = sz;
		end = NULL;
		extra_objs = 0;

		if (max_sz == 0 || max_sz <= sz)
			//max_alloc_size = (next_size << 1);
			max_alloc_size = this->next_size;
		else
			max_alloc_size = max_sz;
	}

	virtual ~TS_FIFO_Object_Pool()
	{
		if (!has_dumped)
			dump();
	}

	virtual void dump() 
	{ 
		if (!has_dumped)
		{
			const size_type offset_ = 2 * this->min_alloc_size;
			const size_type partition_sz = this->requested_size + offset_;

			PODptr<size_type> iter = this->list;

			while(iter.valid())
			{
				register T *ptr_obj = NULL;

				for (register char * block = iter.begin() + iter.element_size() - partition_sz; 
					block != iter.begin(); block -= partition_sz)
				{
					ptr_obj = reinterpret_cast<T*>(block + offset_);
					ptr_obj->~T();
				}

				ptr_obj = reinterpret_cast<T*>(iter.begin() + offset_);
				ptr_obj->~T();

				const PODptr<size_type> next = iter.next();
				iter = next;
			}
			has_dumped = true;
		}
	}

	virtual inline void set_max_size(size_t sz) 
	{
		if (sz == 0 || sz <= this->next_size)
			max_alloc_size = this->next_size;
		else
			max_alloc_size = sz;
	}
	//##ModelId=4C28B0C30165
	virtual element_type * alloc()
	{
		QCStMutexLocker auto_mutex(&this->mutex);

		if (this->first == NULL && alloc_i() == -1)
			return NULL;

		void** ret = static_cast<void**>(this->first) + 2;

		if (this->first == end)
			end = NULL;

		this->first = this->nextof(this->first);

		if ((this->used_objs == max_alloc_size) && (extra_objs > 0))
			*(ret - 2) = (void*)EXTRA_STATE;
		else
		{
			*(ret - 2) = (void*)NORMAL_STATE;
			this->used_objs++;
		}

		return reinterpret_cast<element_type *>(ret);
	}

	//##ModelId=4C28B0C30167
	virtual void free(element_type * &chunk)
	{ 
		QCStMutexLocker auto_mutex(&this->mutex);

		void** ptr_ = reinterpret_cast<void**>(chunk) - 2;

		if (*ptr_ == (void*)EXTRA_STATE)
		{
			chunk->~T();
			delete[](reinterpret_cast<char*>(ptr_));
			extra_objs--;
		}
		else
		{
			if (end == NULL)
			{
				this->nextof(static_cast<void*>(ptr_)) = end;
				this->prevof(static_cast<void*>(ptr_)) = static_cast<void*>(ptr_);
				end = static_cast<void*>(ptr_);
				this->first = end;
			}
			else
			{
				this->nextof(static_cast<void*>(ptr_)) = this->nextof(end);
				this->nextof(end) = static_cast<void*>(ptr_);
				this->prevof(static_cast<void*>(ptr_)) = end;
				end = static_cast<void*>(ptr_);
			}
			this->used_objs--;
		}
		chunk = NULL;
	}

	//##ModelId=4C28B0C301CF
	virtual element_type * acquire()
	{
		element_type* chunk = alloc();

		if (chunk == 0)
			return chunk;

		try { 
			chunk->init();
		}
		catch (...) 
		{ 
			this->free(chunk); 
			throw; 
		}

		return chunk;
	}

	//##ModelId=4C28B0C301D1
	virtual void release(element_type * &chunk)
	{
		chunk->dump();
		this->free(chunk);
	}

	virtual inline size_type get_used_objects(void)
	{
		return this->used_objs + extra_objs;
	}

	virtual inline size_type get_total_objects(void)
	{
		return this->total_size + extra_objs;
	}

	virtual inline size_type get_empty_objects(void)
	{
		return (this->total_size - this->used_objs);
	}

	virtual inline bool is_valid(element_type * const chunk)
	{
		void** ptr_ = reinterpret_cast<void**>(chunk) - 2;

		if (*ptr_ == (void*)EXTRA_STATE ||
			*ptr_ == (void*)NORMAL_STATE)
		{
			return false;
		}
		return true;
	}

protected:
	//##ModelId=4C28B0C30152
	static inline void * & prevof(void * const ptr)
	{
		return *(static_cast<void**>(ptr) + 1); 
	}

	//##ModelId=4C28B0C30159
	virtual void * segregate(void * block,
		size_type sz, 
		size_type partition_sz,
		void * end_ = 0)
	{
		char * old = static_cast<char *>(block)
			+ ((sz - partition_sz) / partition_sz) * partition_sz;

		register const size_type offset_ = 2 * this->min_alloc_size;

		try {
			this->nextof(old) = end_;
			construct(old + offset_);

			if (old == block)
			{
				prevof(old) = old;
				return block;
			}
			else
				prevof(old) = old - partition_sz;

			for (char * iter = old - partition_sz; iter != block;
				old = iter, iter -= partition_sz)
			{
				this->nextof(iter) = old;
				prevof(old) = iter;
				construct(iter + offset_);
			}

			prevof(old) = block;
			this->nextof(block) = old;
			prevof(block) = block;
			construct(static_cast<char *>(block) + offset_);
		}
		catch(...)
		{
			delete[] static_cast<char *>(block);
			return NULL;
		}

		return block;
	}

	//##ModelId=4C28B0C3015F
	virtual void construct(void * ptr)
	{
		element_type * ret = static_cast<element_type*>(ptr);

		try { 
			new (ret) element_type(); 
		}
		catch (...) 
		{ 
			throw; 
		}
	}

	virtual int alloc_i(void)
	{
		if (this->total_size < max_alloc_size)
		{
			const size_type offset_ = 2 * this->min_alloc_size;
			const size_type partition_size = this->requested_size + offset_;
			size_type POD_size = 0;
			if (this->total_size + this->next_size > max_alloc_size)
			{
				POD_size = (max_alloc_size - this->total_size) * partition_size + this->min_alloc_size + sizeof(size_type);
				this->total_size = max_alloc_size;
			}
			else
			{
				POD_size = this->next_size * partition_size + this->min_alloc_size + sizeof(size_type);
				this->total_size += this->next_size;
				this->next_size <<= 1;
			}
			char * const ptr = new (std::nothrow) char[POD_size];

			if (ptr == NULL)
				return -1;

			const PODptr<size_type> node(ptr, POD_size);
			this->first = segregate(node.begin(), node.element_size(), partition_size);
			if (this->first == NULL)
				return -1;
			end = node.begin() + node.element_size() - partition_size;
			/**(static_cast<void**>(first)) = (void*)NORMAL_STATE;*/
			node.next(this->list);
			this->list = node;
		}
		else
		{
			const size_type offset_ = 2 * this->min_alloc_size;
			const size_type POD_size = this->requested_size + offset_;
			char * const ptr = new (std::nothrow) char[POD_size];

			if (ptr == NULL)
				return -1;

			this->first = ptr;
			construct(ptr + offset_);
			*(static_cast<void**>(this->first)) = NULL;
			extra_objs++;
		}
		return 0;
	}
private:
	//##ModelId=4C28B0C30151
	bool has_dumped;
	void *end;
	size_type max_alloc_size;
	size_type extra_objs;
};
#endif

