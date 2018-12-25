
#ifndef DEFAULT_BEST_ITEROT_H
#define DEFAULT_BEST_ITEROT_H
#include"best_message.h"
#include <list>
#include <map>
#include "atomic_count.h"
using namespace best_protocol;
class DefaultBestIterator :public BestIterator
{
	friend class DefaultBestMessge;
	friend class DefaultBestHeadMessage;
private:
	void Initail(std::list<IBestBase*>* bestFieldList);
public:
	DefaultBestIterator();
	///��ȡ��������һ���ڵ�
	virtual void BEST_FUNCTION_CALL_MODE First();
	///���ص�������һ�����
	virtual void BEST_FUNCTION_CALL_MODE Next();

	///�ж��Ƿ񻹴�����һ�����
	virtual bool BEST_FUNCTION_CALL_MODE IsDone();
	///ɾ����������ǰ�ڵ�
	virtual bool BEST_FUNCTION_CALL_MODE Erase();

	///��ȡ���������ݽڵ�
	virtual IBestBase* CurrentItem() const;
};


class DefaultBestListIterator :public BestIterator
{
	friend class DefaultBestMessge;
private:
	void Initail(std::list<IBestBase*>* bestFieldList);
public:
	DefaultBestListIterator();
	///��ȡ��������һ���ڵ�
	virtual void BEST_FUNCTION_CALL_MODE First();
	///���ص�������һ�����
	virtual void BEST_FUNCTION_CALL_MODE Next();

	///�ж��Ƿ񻹴�����һ�����
	virtual bool BEST_FUNCTION_CALL_MODE IsDone();
	///ɾ����������ǰ�ڵ�
	virtual bool BEST_FUNCTION_CALL_MODE Erase();

	///��ȡ���������ݽڵ�
	virtual IBestBase* CurrentItem() const;
private:
	std::list<IBestBase*>* m_bestFieldList;
	std::list<IBestBase*>::iterator m_pCurrent;
};


class DefaultBestMapIterator :public BestIterator
{
	friend class DefaultBestHeadMessage;
	friend class DefaultBestDataHeadMessage;
private:
	void Initail(std::map<int32, IBestField*>* bestFieldMap);
public:
	DefaultBestMapIterator();
	///��ȡ��������һ���ڵ�
	virtual void BEST_FUNCTION_CALL_MODE First();
	///���ص�������һ�����
	virtual void BEST_FUNCTION_CALL_MODE Next();

	///�ж��Ƿ񻹴�����һ�����
	virtual bool BEST_FUNCTION_CALL_MODE IsDone();
	///ɾ����������ǰ�ڵ�
	virtual bool BEST_FUNCTION_CALL_MODE Erase();

	///��ȡ���������ݽڵ�
	virtual IBestBase* CurrentItem() const;
private:
	std::map<int, IBestField*>* m_bestFieldList;
	std::map<int, IBestField*>::iterator m_pCurrent;
};
#endif