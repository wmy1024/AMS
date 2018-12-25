
#ifndef DEFAULT_BEST_RECORD_H
#define DEFAULT_BEST_RECORD_H
#include"best_message.h"
#include "atomic_count.h"
#include "default_bestIteror.h"
#include <string>
using namespace best_protocol;
class DefaultBestRecord :public  IBestRecord
{
private:
	atomic_count m_ref;
public:
	DefaultBestRecord(){  }
	virtual ~DefaultBestRecord(){};
	///��ȡ$tag���ֶ�,NULL��ʾ������
	virtual IBestField*  BEST_FUNCTION_CALL_MODE GetField(const int32& tag);
	///����$tag���ֶ�
	virtual void BEST_FUNCTION_CALL_MODE SetField(const int32& tag, IBestField* field);
	///�ж�$tag���ֶ��Ƿ����
	virtual bool BEST_FUNCTION_CALL_MODE IsExistField(const int32& tag);
	///����һ�������Ƶ�����
	virtual int32 BEST_FUNCTION_CALL_MODE CopyFrom(const IBestRecord *other);
	///��������
	virtual IBestRecord* BEST_FUNCTION_CALL_MODE Clone();
	///��ȡ�ֶε�����
	virtual DefaultBestIterator* BEST_FUNCTION_CALL_MODE GetIterator();
private:
	DefaultBestIterator	m_defaultIterator;
	PROTOCAL_TYPE m_protocol_type;

public:
	/************************IBestBase�ӿ�*************************/
	///�������ü�������������
	virtual IBestBase*  BEST_FUNCTION_CALL_MODE AddRef();

	///�������ü�������Ϊ0ʱ�ͷ�����
	virtual uint64  BEST_FUNCTION_CALL_MODE Release();

	///����BEST��������
	virtual BEST_OBJECT_TYPE  BEST_FUNCTION_CALL_MODE GetBestType();

	///������������
	virtual int32 BEST_FUNCTION_CALL_MODE SetOwner(IBestBase* best_base);

	///��ȡ��������
	virtual IBestBase* BEST_FUNCTION_CALL_MODE GetOwner();

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
	virtual int32  BEST_FUNCTION_CALL_MODE Status();
	///�������л���
	virtual int32   BEST_FUNCTION_CALL_MODE SetBestSerializer(IBestSerializer* serializer);
	///��ȡ���л���
	virtual IBestSerializer* BEST_FUNCTION_CALL_MODE GetBestSerializer();

	// ��ȡ��ǰ�ֶε�Э��
	virtual const PROTOCAL_TYPE BEST_FUNCTION_CALL_MODE GetProtocal();
    //����Э��
	virtual int32 BEST_FUNCTION_CALL_MODE SetProtocal(PROTOCAL_TYPE protpcal);
};
#endif