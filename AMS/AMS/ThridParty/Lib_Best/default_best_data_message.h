
#ifndef DEFAULT_BEST_DATA_MESSAGE_H
#define DEFAULT_BEST_DATA_MESSAGE_H
#include "default_bestIteror.h"
#include"best_message.h"
#include <list>
#include "atomic_count.h"
#include "default_best_field.h"
#include "default_message_pool.h"
using namespace best_protocol;

#pragma pack(1)
typedef struct BestDataHeadStruct_t
{
	BestDataHeadStruct_t()
	{
		memset(this, 0, sizeof(BestDataHeadStruct_t));
	}
	int32 head_length;
	int32 content_length;
}BestDataHeadStruct_t;
#pragma pack()

class DefaultBestDataHeadMessage:public IBestHeadMessage
{
private:
	atomic_count m_ref;
	PROTOCAL_TYPE m_protocol_type;
public:
	DefaultBestDataHeadMessage()
	{ 
		m_protocol_type = BEST_HEAD_STAMP;
		m_status = 0;
		m_best_buffer = NULL;
		m_data_msg = NULL;
		memset(&m_best_head_struct, 0, sizeof(BestDataHeadStruct_t));
		m_best_field_map.clear();
		m_defaultIterator.Initail(&m_best_field_map);
	}
	virtual ~DefaultBestDataHeadMessage(){};

	///��ȡͷ������,0��ʾ��ǰ�޷���ȡͷ������
	virtual int32 BEST_FUNCTION_CALL_MODE GetHeadLength();

	///��ȡ���ݳ���,0��ʾ��ǰ�޷���ȡ���ݳ���
	virtual int32 BEST_FUNCTION_CALL_MODE GetDataLength();

	virtual void BEST_FUNCTION_CALL_MODE  SetDataLength(int32 data_lenght);

	/******************************************�������ݲ�******************************************/
	///�������ݲ���Ϣ
	virtual int32 BEST_FUNCTION_CALL_MODE SetDataMessage(IBestDataMessage* data_msg);
	///��ȡ���ݲ���Ϣ
	virtual IBestDataMessage* BEST_FUNCTION_CALL_MODE GetDataMessage();
	///����һ����Ϣ���Ƶ�����
	virtual int32 BEST_FUNCTION_CALL_MODE CopyFrom(const IBestHeadMessage* other);
	///��������
	virtual IBestHeadMessage* BEST_FUNCTION_CALL_MODE Clone();

	/**********************************��ȡ������*************************/

	///��ȡ$tag���ֶ�,NULL��ʾ������
	virtual IBestField*  BEST_FUNCTION_CALL_MODE GetField(const int32& tag);

	///����$tag���ֶ�
	virtual void BEST_FUNCTION_CALL_MODE SetField(const int32& tag, IBestField* field);

	///�ж�$tag���ֶ��Ƿ����
	virtual bool BEST_FUNCTION_CALL_MODE IsExistField(const int32& tag);

	///��ȡ�ֶε�����
	virtual BestIterator* BEST_FUNCTION_CALL_MODE GetIterator(){ return  &m_defaultIterator; }

	//��ȡ��ǰ�ֶε�Э��
	virtual const PROTOCAL_TYPE BEST_FUNCTION_CALL_MODE GetProtocal();

	int32 SetProtocal(PROTOCAL_TYPE protpcal = BEST_HEAD_STAMP);

	///
public:
	/************************IBestBase�ӿ�*************************/
	///�������ü�������������
	virtual IBestBase*  BEST_FUNCTION_CALL_MODE AddRef()
	{
		if(++m_ref == 1)
		{
			m_data_msg = 0;
		}
		return this;
	}
	///�������ü�������Ϊ0ʱ�ͷ�����
	virtual uint64  BEST_FUNCTION_CALL_MODE Release();
	///����BEST��������
	virtual BEST_OBJECT_TYPE  BEST_FUNCTION_CALL_MODE GetBestType(){ return OBJ_NONE; }

	///������������
	virtual int32 BEST_FUNCTION_CALL_MODE SetOwner(IBestBase* best_base){ return 0; }

	///��ȡ��������
	virtual IBestBase* BEST_FUNCTION_CALL_MODE GetOwner(){ return 0; }

	/****************************IBestStream�ӿ�******************************/
	///���л�����
	virtual const void*  BEST_FUNCTION_CALL_MODE Serialize(int32* len);
	///�����л�
	virtual int32 BEST_FUNCTION_CALL_MODE Deserialize();
	///������
	virtual int32	BEST_FUNCTION_CALL_MODE SetBuffer(const void* buffer, const int32& len);
	///��ȡ��
	virtual void*  BEST_FUNCTION_CALL_MODE GetBuffer(int32* len);
	///������״̬. 1:���� 0:������
	virtual int32  BEST_FUNCTION_CALL_MODE Status(){ return m_status; }
	///�������л���
	virtual int32   BEST_FUNCTION_CALL_MODE SetBestSerializer(IBestSerializer* serializer){ return 0; }
	///��ȡ���л���
	virtual IBestSerializer* BEST_FUNCTION_CALL_MODE GetBestSerializer(){ return 0; }
	///
	std::map<int, IBestField*> m_best_field_map;
	BestDataHeadStruct_t       m_best_head_struct;
	DefaultBestMapIterator	   m_defaultIterator;
	BestBuffer*                m_best_buffer;
	int32                      m_status;
	DefaultBestDataMessage*    m_data_msg;
};

class DefaultBestDataMessage :public IBestDataMessage
{
private:
	atomic_count m_ref;
	BestBuffer* m_best_buffer;
	int32 m_status;
public:
	DefaultBestDataMessage(){
		m_best_buffer = NULL; 
		m_status = 0;
	}

	///����һ�������Ƶ�����
	virtual int32 BEST_FUNCTION_CALL_MODE CopyFrom(const IBestDataMessage *other);
	///��������
	virtual IBestDataMessage* BEST_FUNCTION_CALL_MODE Clone();

	virtual void BEST_FUNCTION_CALL_MODE SetGroup(const int32& flag, IBestGroup* group) {}

	virtual IBestGroup* BEST_FUNCTION_CALL_MODE GetGroup(const int32& flag) { return 0; }

	virtual bool BEST_FUNCTION_CALL_MODE IsExitGroup(const int32& flag) { return false; }

	///��ȡ$tag���ֶ�,NULL��ʾ������
	virtual IBestField*  BEST_FUNCTION_CALL_MODE GetField(const int32& tag);

	///����$tag���ֶ�
	virtual void BEST_FUNCTION_CALL_MODE SetField(const int32& tag, IBestField* field);

	///�ж�$tag���ֶ��Ƿ����
	virtual bool BEST_FUNCTION_CALL_MODE IsExistField(const int32& tag);

	///��ȡ�ֶε�����
	virtual BestIterator* BEST_FUNCTION_CALL_MODE GetIterator() { return &m_defaultIterator; }

	//��ȡ��ǰ�ֶε�Э��
	virtual const PROTOCAL_TYPE BEST_FUNCTION_CALL_MODE GetProtocal();

	virtual int32 BEST_FUNCTION_CALL_MODE SetProtocal(PROTOCAL_TYPE protpcal);

	int ReleaseBuffer();

private:

	DefaultBestDataHeadMessage* m_best_data_head_message;

	DefaultBestIterator	m_defaultIterator;

	PROTOCAL_TYPE m_protocol_type;

public:
	/************************IBestBase�ӿ�*************************/
	///�������ü�������������
	virtual IBestBase*  BEST_FUNCTION_CALL_MODE AddRef();

	virtual void Init();

	///�������ü�������Ϊ0ʱ�ͷ�����
	virtual uint64  BEST_FUNCTION_CALL_MODE Release();
	///����BEST��������
	virtual BEST_OBJECT_TYPE  BEST_FUNCTION_CALL_MODE GetBestType(){ return OBJ_NONE; }

	///������������
	virtual int32 BEST_FUNCTION_CALL_MODE SetOwner(IBestBase* best_base){ return 0; }

	///��ȡ��������
	virtual IBestBase* BEST_FUNCTION_CALL_MODE GetOwner(){ return 0; }

	/****************************IBestStream�ӿ�******************************/
	///���л�����
	virtual const void*  BEST_FUNCTION_CALL_MODE Serialize(int32* len);
	///�����л�
	virtual int32 BEST_FUNCTION_CALL_MODE Deserialize();

	///����ͷ����
	virtual int32	BEST_FUNCTION_CALL_MODE SetHeadBuffer(const void* buffer, const int32& len);
	///��ȡͷ����
	virtual void*  BEST_FUNCTION_CALL_MODE GetHeadBuffer(int32* len);
	///���л�ͷ������
	virtual const void*  BEST_FUNCTION_CALL_MODE SerializeHead(int32* len);
	///�����л�ͷ��
	virtual int32 BEST_FUNCTION_CALL_MODE DeserializeHead();

	///��ȡ���ݲ���Ϣ
	virtual IBestHeadMessage* BEST_FUNCTION_CALL_MODE GetDataHeadMessage()
	{
		return (IBestHeadMessage*)m_best_data_head_message;
	}
	///������
	virtual int32	BEST_FUNCTION_CALL_MODE SetBuffer(const void* buffer, const int32& len);
	///��ȡ��
	virtual void*  BEST_FUNCTION_CALL_MODE GetBuffer(int32* len);

	///������״̬. 1:���� 0:������
	virtual int32  BEST_FUNCTION_CALL_MODE Status();
	///�������л���
	virtual int32   BEST_FUNCTION_CALL_MODE SetBestSerializer(IBestSerializer* serializer){ return 0; }
	///��ȡ���л���
	virtual IBestSerializer* BEST_FUNCTION_CALL_MODE GetBestSerializer(){ return 0; }
};
#endif