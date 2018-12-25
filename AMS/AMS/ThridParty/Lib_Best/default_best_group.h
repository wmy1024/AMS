

#ifndef DEFAULT_BEST_GROUP_H
#define DEFAULT_BEST_GROUP_H
#include"best_message.h"
#include "atomic_count.h"
#include "default_bestIteror.h"
#include <string>
using namespace best_protocol;
class DefaultBestGroup :public IBestGroup
{
private:
	atomic_count m_ref;
	PROTOCAL_TYPE m_protocal_type;
public:
	DefaultBestGroup(){  }
	virtual ~DefaultBestGroup(){};
	///����һ����¼,�������Ӻ�ļ�¼����
	virtual IBestRecord * BEST_FUNCTION_CALL_MODE AddRecord();
	///����һ���Ѵ��ڵļ�¼
	virtual int BEST_FUNCTION_CALL_MODE AddRecord(IBestRecord * best_record);

	///��ȡ��¼������
	virtual DefaultBestIterator* BEST_FUNCTION_CALL_MODE GetIterator();

	///����һ�������Ƶ�����
	virtual int32 BEST_FUNCTION_CALL_MODE CopyFrom(const IBestGroup* other);

	///��������
	virtual IBestGroup* BEST_FUNCTION_CALL_MODE Clone() const;

	// ��ȡ��ǰ�ֶε�Э��
	virtual const PROTOCAL_TYPE BEST_FUNCTION_CALL_MODE GetProtocal();
	//����Э������
	virtual int32 BEST_FUNCTION_CALL_MODE SetProtocal(PROTOCAL_TYPE protpcal);
private:
	DefaultBestIterator	m_defaultIterator;

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

};
#endif