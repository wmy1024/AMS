
#ifndef DEFAULT_HEAD_MESSAGE_H
#define DEFAULT_HEAD_MESSAGE_H
#include"best_message.h"
#include <list>
#include <map>
#include <string>
#include "atomic_count.h"
#include "default_bestIteror.h"
#include "default_message_pool.h"
#include "default_best_data_message.h"
#include "default_best_field.h"
#include <string.h>
using namespace best_protocol;

#pragma pack(1)
typedef struct BestHeadStruct_t
{
	BestHeadStruct_t()
	{
		memset(this, 0, sizeof(BestHeadStruct_t));
	}
	int32 head_length;
	int32 content_length;
}BestHeadStruct;

#pragma pack()
class DefaultBestHeadMessage :public IBestHeadMessage
{
private:
	atomic_count m_ref;
	PROTOCAL_TYPE m_protocol_type;
	DefaultBestDataMessage* m_data_msg;

public:
	DefaultBestHeadMessage()
	{ 
		m_status = 0;
		m_best_buffer = NULL;
		m_data_msg = NULL;
		memset(&m_best_head_struct, 0, sizeof(BestHeadStruct));
		m_defaultIterator.Initail(&m_best_field_map);
	}
	virtual ~DefaultBestHeadMessage(){}

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

private:
	DefaultBestMapIterator	m_defaultIterator;
	BestBuffer* m_best_buffer;
	int32 m_status;
public:
	std::map<int, IBestField*> m_best_field_map;
	BestHeadStruct m_best_head_struct;

public:
	/************************IBestBase�ӿ�*************************/
	///�������ü�������������
	virtual IBestBase*  BEST_FUNCTION_CALL_MODE AddRef();

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

	virtual int32 BEST_FUNCTION_CALL_MODE SetProtocal(PROTOCAL_TYPE protpcal);

	int ReleaseBuffer();
};
#endif