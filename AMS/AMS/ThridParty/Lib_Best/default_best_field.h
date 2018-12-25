

#ifndef DEFAULT_BEST_FIELD_H
#define DEFAULT_BEST_FIELD_H
#include"best_message.h"
#include "atomic_count.h"
#include <string>
#include "default_message_pool.h"
using namespace best_protocol;
class DefaultBestField :public IBestField
{
private:
	atomic_count m_ref;
	PROTOCAL_TYPE m_protocol_type;
public:
	DefaultBestField();
	virtual ~DefaultBestField(){};
	/************************IBestBase�ӿ�*************************/
	///�������ü�������������
	virtual IBestBase*  BEST_FUNCTION_CALL_MODE AddRef(){
		++m_ref;
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
	virtual const void*  BEST_FUNCTION_CALL_MODE Serialize(int32* len){ return 0; }
	///�����л�
	virtual int32 BEST_FUNCTION_CALL_MODE Deserialize(){ return 0; }

	///������
	virtual int32	BEST_FUNCTION_CALL_MODE SetBuffer(const void* buffer, const int32& len){ return 0; }
	///��ȡ��
	virtual void*  BEST_FUNCTION_CALL_MODE GetBuffer(int32* len){ return 0; }
	///������״̬. 1:���� 0:������
	virtual int32  BEST_FUNCTION_CALL_MODE Status(){ return 0; }
	///�������л���
	virtual int32   BEST_FUNCTION_CALL_MODE SetBestSerializer(IBestSerializer* serializer){ return 0; }
	///��ȡ���л���
	virtual IBestSerializer* BEST_FUNCTION_CALL_MODE GetBestSerializer(){ return 0; }

	/*******************��ȡ�����ö�Ӧ��Filedֵ*****************/
	virtual uint8	BEST_FUNCTION_CALL_MODE GetInt8() const;
	virtual void  BEST_FUNCTION_CALL_MODE SetInt8(uint8 val);
	virtual uint16 BEST_FUNCTION_CALL_MODE GetInt16() const;
	virtual void  BEST_FUNCTION_CALL_MODE SetInt16(uint16 val);
	virtual uint32	BEST_FUNCTION_CALL_MODE GetInt32() const;
	virtual void BEST_FUNCTION_CALL_MODE SetInt32(uint32 val);
	virtual uint64	BEST_FUNCTION_CALL_MODE GetInt64() const;
	virtual void BEST_FUNCTION_CALL_MODE SetInt64(uint64 val);
	virtual const char*  BEST_FUNCTION_CALL_MODE GetString() const;
	virtual void  BEST_FUNCTION_CALL_MODE SetString(const char* val);
	//virtual const void*  BEST_FUNCTION_CALL_MODE GetRawData(int* data_len = 0) const ;
	virtual int32 BEST_FUNCTION_CALL_MODE GetRawDataLen() const;
	virtual void*  BEST_FUNCTION_CALL_MODE GetRawData(int* data_len = 0);
	virtual void  BEST_FUNCTION_CALL_MODE SetRawData(const void* raw_data, int data_len);
	///��ȡ�ֶε���������
	virtual FIELD_VALUE_TYPE BEST_FUNCTION_CALL_MODE GetValueType();
	///����һ�������Ƶ�����
	virtual int32 BEST_FUNCTION_CALL_MODE CopyFrom(const IBestField *other);
	///��������
	virtual IBestField* BEST_FUNCTION_CALL_MODE Clone();
	virtual const PROTOCAL_TYPE BEST_FUNCTION_CALL_MODE GetProtocal();
	virtual int32 BEST_FUNCTION_CALL_MODE SetProtocal(PROTOCAL_TYPE protpcal);
	virtual uint32 BEST_FUNCTION_CALL_MODE GetTag();
	virtual int32 BEST_FUNCTION_CALL_MODE SetTag(uint32 tag);
private:
	void Reset();
private:
	uint8 m_uint8_value;
	uint16 m_uint16_value;
	uint32 m_uint32_value;
	uint64 m_uint64_value;
	uint32 m_tag;
	std::string m_string;
	FIELD_VALUE_TYPE m_value_type;
	BestBuffer* m_bestBuffer;
};
#endif