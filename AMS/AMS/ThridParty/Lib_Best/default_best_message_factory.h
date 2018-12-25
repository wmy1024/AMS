#ifndef DEFAULT_BEST_MESSAGE_FACTORY_H
#define DEFAULT_BEST_MESSAGE_FACTORY_H
#include <map>
#include <string>
#include "best_message.h"

using namespace best_protocol;
class DefaultBestMessgeFactory :public IBestMessgeFactory
{
	static DefaultBestMessgeFactory *m_pInstance;
public:
	static DefaultBestMessgeFactory* GetInstance()
	{
		if (m_pInstance == 0)  //�ж��Ƿ��һ�ε���  
			m_pInstance = new DefaultBestMessgeFactory();
		return m_pInstance;
	}
	static std::map<PROTOCAL_TYPE, IBestSerializer*> m_best_serianlizer_map;
	///����BestMessage��Ϣ������Э��������л���
	virtual IBestMessge* BEST_FUNCTION_CALL_MODE CreateBestMessage(PROTOCAL_TYPE protocal_type);
	

	///����BestRPCͷ����Ϣ
	virtual IBestRPCHead* BEST_FUNCTION_CALL_MODE CreateRpcHead(PROTOCAL_TYPE protocal_type);
	

	///����Bestͷ����Ϣ
	virtual IBestHeadMessage* BEST_FUNCTION_CALL_MODE CreateHeadMessage(PROTOCAL_TYPE protocal_type);
	

	///����BestMessage��Ϣ������Э��������л���
	virtual IBestDataMessage* BEST_FUNCTION_CALL_MODE CreateDataMessage(PROTOCAL_TYPE protocal_type);
	

	///����BestGroup��Ϣ������Э��������л���
	virtual IBestGroup* BEST_FUNCTION_CALL_MODE CreateBestGroup(PROTOCAL_TYPE protocal_type);
	

	///����Best��¼��Ϣ������Э��������л���
	virtual IBestRecord* BEST_FUNCTION_CALL_MODE CreateBestRecord(PROTOCAL_TYPE protocal_type);
	

	///����Best�ֶΣ�����Э��������л���
	virtual IBestField* BEST_FUNCTION_CALL_MODE CreateBestField(PROTOCAL_TYPE protocal_type);
	
	///����Э�鷵�����л���
	virtual IBestSerializer* BEST_FUNCTION_CALL_MODE GetSerializer(PROTOCAL_TYPE protocal_type);
	
};
#endif