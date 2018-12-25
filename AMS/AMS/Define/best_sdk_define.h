#ifndef BEST_MESSAGE_SDK_DEFINE_H
#define BEST_MESSAGE_SDK_DEFINE_H

typedef enum PLUG_NAME
{
	PLUG_BASE_MGR    = 1,
	PLUG_DATA_MGR    = 2,
	PLUG_CLIENT_MGR  = 3,
	PLUG_CTP_MGR     = 4,
	PLUG_MYSQL_MGR   = 5,
	PLUG_REDIS_MGR   = 6,
	PLUG_QUOTE_MGR   = 7,
	PLUG_CACULATE_PLUG = 8,
	PLUG_RISK_CONTROL_PLUG = 9,
}PLUG_NAME;

///���ݹ���ģ���ڲ�
const int GW_ROUTE_MESSAGE_PHASE         = 10000 ;
const int GW_ROUTE_MESSAGE_PHASE_TREE    = 10001 ;
const int GW_ROUTE_MESSAGE_SRC_CONNECTID = 10002 ;
const int GW_ROUTE_MESSAGE_DATA_INTERNAL_REQUEST = 10003 ;
/// �������ͣ�uint32; ������·�ɲ�����
const int GW_ROUTE_ERROR_NO  = 10003 ;
const int GW_ROUTE_MOUDLE_ID = 10004 ;
const int GW_ROUTE_ORDER_ID  = 10005 ;


///ҵ������
//����˽���������ݡ����������򲻻��յ�˽���������ݡ�
const int AS_SDK_USER_SUBSCRIBEPRIVATETOPIC                   = 20001;
//���Ĺ����������ݡ����������򲻻��յ������������ݡ�
const int AS_SDK_USER_SUBSCRIBEPUBLICTOPIC                    = 20002;
//�ͻ�����֤����
const int AS_SDK_USER_REQAUTHENTICATE                         = 20003;
//�û���¼����
const int AS_SDK_USER_REQUSERLOGIN                            = 20004;
//�ǳ�����
const int AS_SDK_USER_REQUSERLOGOUT                           = 20005;
//�û������������
const int AS_SDK_USER_REQUSERPASSWORDUPDATE                   = 20006;
//�ʽ��˻������������
const int AS_SDK_USER_REQTRADINGACCOUNTPASSWORDUPDATE         = 20007;
//��¼����2
const int AS_SDK_USER_REQUSERLOGIN2                           = 20008;
//�û������������2
const int AS_SDK_USER_REQUSERPASSWORDUPDATE2                  = 20009;
//����¼������
const int AS_SDK_USER_REQORDERINSERT                          = 20010;
//Ԥ��¼������
const int AS_SDK_USER_REQPARKEDORDERINSERT                    = 20011;
//Ԥ�񳷵�¼������
const int AS_SDK_USER_REQPARKEDORDERACTION                    = 20012;
//������������
const int AS_SDK_USER_REQORDERACTION                          = 20013;
//��ѯ��󱨵���������
const int AS_SDK_USER_REQQUERYMAXORDERVOLUME                  = 20014;
//Ͷ���߽�����ȷ��
const int AS_SDK_USER_REQSETTLEMENTINFOCONFIRM                = 20015;
//����ɾ��Ԥ��
const int AS_SDK_USER_REQREMOVEPARKEDORDER                    = 20016;
//����ɾ��Ԥ�񳷵�
const int AS_SDK_USER_REQREMOVEPARKEDORDERACTION              = 20017;
//ִ������¼������
const int AS_SDK_USER_REQEXECORDERINSERT                      = 20018;
//ִ�������������
const int AS_SDK_USER_REQEXECORDERACTION                      = 20019;
//ѯ��¼������
const int AS_SDK_USER_REQFORQUOTEINSERT                       = 20020;
//����¼������
const int AS_SDK_USER_REQQUOTEINSERT                          = 20021;
//���۲�������
const int AS_SDK_USER_REQQUOTEACTION                          = 20022;
//����������������
const int AS_SDK_USER_REQBATCHORDERACTION                     = 20023;
//��Ȩ�ԶԳ�¼������
const int AS_SDK_USER_REQOPTIONSELFCLOSEINSERT                = 20024;
//��Ȩ�ԶԳ��������
const int AS_SDK_USER_REQOPTIONSELFCLOSEACTION                = 20025;
//�������¼������
const int AS_SDK_USER_REQCOMBACTIONINSERT                     = 20026;
//�����ѯ����
const int AS_SDK_USER_REQQRYORDER                             = 20027;
//�����ѯ�ɽ�
const int AS_SDK_USER_REQQRYTRADE                             = 20028;
//�����ѯͶ���ֲ߳�
const int AS_SDK_USER_REQQRYINVESTORPOSITION                  = 20029;
//�����ѯ�ʽ��˻�
const int AS_SDK_USER_REQQRYTRADINGACCOUNT                    = 20030;
//�����ѯͶ����
const int AS_SDK_USER_REQQRYINVESTOR                          = 20031;
//�����ѯ���ױ���
const int AS_SDK_USER_REQQRYTRADINGCODE                       = 20032;
//�����ѯ��Լ��֤����
const int AS_SDK_USER_REQQRYINSTRUMENTMARGINRATE              = 20033;
//�����ѯ��Լ��������
const int AS_SDK_USER_REQQRYINSTRUMENTCOMMISSIONRATE          = 20034;
//�����ѯ������
const int AS_SDK_USER_REQQRYEXCHANGE                          = 20035;
//�����ѯ��Ʒ
const int AS_SDK_USER_REQQRYPRODUCT                           = 20036;
//�����ѯ��Լ
const int AS_SDK_USER_REQQRYINSTRUMENT                        = 20037;
//�����ѯ����
const int AS_SDK_USER_REQQRYDEPTHMARKETDATA                   = 20038;
//�����ѯͶ���߽�����
const int AS_SDK_USER_REQQRYSETTLEMENTINFO                    = 20039;
//�����ѯת������
const int AS_SDK_USER_REQQRYTRANSFERBANK                      = 20040;
//�����ѯͶ���ֲ߳���ϸ
const int AS_SDK_USER_REQQRYINVESTORPOSITIONDETAIL            = 20041;
//�����ѯ�ͻ�֪ͨ
const int AS_SDK_USER_REQQRYNOTICE                            = 20042;
//�����ѯ������Ϣȷ��
const int AS_SDK_USER_REQQRYSETTLEMENTINFOCONFIRM             = 20043;
//�����ѯͶ���ֲ߳���ϸ
const int AS_SDK_USER_REQQRYINVESTORPOSITIONCOMBINEDETAIL     = 20044;
//�����ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ
const int AS_SDK_USER_REQQRYCFMMCTRADINGACCOUNTKEY            = 20045;
//�����ѯ�ֵ��۵���Ϣ
const int AS_SDK_USER_REQQRYEWARRANTOFFSET                    = 20046;
//�����ѯͶ����Ʒ��/��Ʒ�ֱ�֤��
const int AS_SDK_USER_REQQRYINVESTORPRODUCTGROUPMARGIN        = 20047;
//�����ѯ��������֤����
const int AS_SDK_USER_REQQRYEXCHANGEMARGINRATE                = 20048;
//�����ѯ������������֤����
const int AS_SDK_USER_REQQRYEXCHANGEMARGINRATEADJUST          = 20049;
//�����ѯ����
const int AS_SDK_USER_REQQRYEXCHANGERATE                      = 20050;
//�����ѯ�����������Ա����Ȩ��
const int AS_SDK_USER_REQQRYSECAGENTACIDMAP                   = 20051;
//�����ѯ��Ʒ���ۻ���
const int AS_SDK_USER_REQQRYPRODUCTEXCHRATE                   = 20052;
//�����ѯ��Ʒ��
const int AS_SDK_USER_REQQRYPRODUCTGROUP                      = 20053;
//�����ѯ�����̺�Լ��������
const int AS_SDK_USER_REQQRYMMINSTRUMENTCOMMISSIONRATE        = 20054;
//�����ѯ��������Ȩ��Լ������
const int AS_SDK_USER_REQQRYMMOPTIONINSTRCOMMRATE             = 20055;
//�����ѯ����������
const int AS_SDK_USER_REQQRYINSTRUMENTORDERCOMMRATE           = 20056;
//�����ѯ�ʽ��˻�
const int AS_SDK_USER_REQQRYSECAGENTTRADINGACCOUNT            = 20057;
//�����ѯ�����������ʽ�У��ģʽ
const int AS_SDK_USER_REQQRYSECAGENTCHECKMODE                 = 20058;
//�����ѯ��Ȩ���׳ɱ�
const int AS_SDK_USER_REQQRYOPTIONINSTRTRADECOST              = 20059;
//�����ѯ��Ȩ��Լ������
const int AS_SDK_USER_REQQRYOPTIONINSTRCOMMRATE               = 20060;
//�����ѯִ������
const int AS_SDK_USER_REQQRYEXECORDER                         = 20061;
//�����ѯѯ��
const int AS_SDK_USER_REQQRYFORQUOTE                          = 20062;
//�����ѯ����
const int AS_SDK_USER_REQQRYQUOTE                             = 20063;
//�����ѯ��Ȩ�ԶԳ�
const int AS_SDK_USER_REQQRYOPTIONSELFCLOSE                   = 20064;
//�����ѯͶ�ʵ�Ԫ
const int AS_SDK_USER_REQQRYINVESTUNIT                        = 20065;
//�����ѯ��Ϻ�Լ��ȫϵ��
const int AS_SDK_USER_REQQRYCOMBINSTRUMENTGUARD               = 20066;
//�����ѯ�������
const int AS_SDK_USER_REQQRYCOMBACTION                        = 20067;
//�����ѯת����ˮ
const int AS_SDK_USER_REQQRYTRANSFERSERIAL                    = 20068;
//�����ѯ����ǩԼ��ϵ
const int AS_SDK_USER_REQQRYACCOUNTREGISTER                   = 20069;
//�����ѯǩԼ����
const int AS_SDK_USER_REQQRYCONTRACTBANK                      = 20070;
//�����ѯԤ��
const int AS_SDK_USER_REQQRYPARKEDORDER                       = 20071;
//�����ѯԤ�񳷵�
const int AS_SDK_USER_REQQRYPARKEDORDERACTION                 = 20072;
//�����ѯ����֪ͨ
const int AS_SDK_USER_REQQRYTRADINGNOTICE                     = 20073;
//�����ѯ���͹�˾���ײ���
const int AS_SDK_USER_REQQRYBROKERTRADINGPARAMS               = 20074;
//�����ѯ���͹�˾�����㷨
const int AS_SDK_USER_REQQRYBROKERTRADINGALGOS                = 20075;
//�����ѯ��������û�����
const int AS_SDK_USER_REQQUERYCFMMCTRADINGACCOUNTTOKEN        = 20076;
//�ڻ����������ʽ�ת�ڻ�����
const int AS_SDK_USER_REQFROMBANKTOFUTUREBYFUTURE             = 20077;
//�ڻ������ڻ��ʽ�ת��������
const int AS_SDK_USER_REQFROMFUTURETOBANKBYFUTURE             = 20078;
//�ڻ������ѯ�����������
const int AS_SDK_USER_REQQUERYBANKACCOUNTMONEYBYFUTURE        = 20079;


//ctp����֪ͨ
//const int AS_SDK_ONRTN_ORDER_INSERT                           = 20080;//����������
const int AS_SDK_USER_ONRTNORDER                              = 20080;//��ʽ����
//ctp������������(����)����Ӧ
//const int AS_SDK_ONRTN_USER_REQORDERACTION                    = 20081;//����������
const int AS_SDK_USER_ONRSPORDERACTION                        = 20081;//��ʽ����
//ctp�ɽ�֪ͨ
//const int AS_SDK_ONRTN_USER_ORDERTRADE                        = 20082;//����������
const int AS_SDK_USER_ONRTNTRADE                              = 20082;//��ʽ����

//��ѯ������Ӧ
const int AS_SDK_USER_ONRSPQRYORDER                                = 20083;
//��ѯ�ɽ���Ӧ
const int AS_SDK_USER_ONRSPQRYTRADE                                = 20084;
//��ѯͶ���ֲ߳���Ӧ
const int AS_SDK_USER_ONRSPQRYINVESTORPOSITION                     = 20085;
//��ѯ�ʽ��˻���Ӧ
const int AS_SDK_USER_ONRSPQRYTRADINGACCOUNT                       = 20086;
//��ѯ��Լ��Ӧ
const int AS_SDK_USER_ONRSPQRYINSTRUMENT                           = 20087;
//��ѯ��Լ��Ӧ(���˻�)
const int AS_SDK_USER_ONRSPQRYINSTRUMENT_MAIN_ACCOUNT              = 20088;
//��ѯͶ���ֲ߳���Ӧ(���˻�)
const int AS_SDK_USER_ONRSPQRYINVESTORPOSITION_MAIN_ACCOUNT        = 20089;
//��ѯ������Ӧ(���˻�)
const int AS_SDK_USER_ONRSPQRYORDER_MAIN_ACCOUNT                   = 20090;
//��ѯ�ɽ���Ӧ(���˻�)
const int AS_SDK_USER_ONRSPQRYTRADE_MAIN_ACCOUNT                   = 20091;
//��ѯͶ���ֲ߳���ϸ��Ӧ(���˻�)
const int AS_SDK_USER_ONRSPQRYINVESTORPOSITIONDETAIL_MAIN_ACCOUNT  = 20092;
//��ѯ�ʽ��˻���Ӧ(���˻�)
const int AS_SDK_USER_ONRSPQRYTRADINGACCOUNT_MAIN_ACCOUNT          = 20093;
//��¼������Ӧ(���˻�)
const int AS_SDK_USER_ONRSPUSERLOGIN_MAIN_ACCOUNT                  = 20094;
//��ѯͶ���ֲ߳���ϸ��Ӧ
const int AS_SDK_USER_ONRSPQRYINVESTORPOSITIONDETAIL               = 20095;
//�����д���ʱ�ı���¼��������Ӧ
const int AS_SDK_USER_ONRSPORDERINSERT                             = 20096;
//��ѯ���������Ӧ(���˻�)
const int AS_SDK_USER_ONRSPQRYDEPTHMARKETDATA_MAIN_ACCOUNT         = 20097;
//��¼������Ӧ
const int AS_SDK_USER_ONRSPUSERLOGIN                               = 20098;
//�ǳ�������Ӧ
const int AS_SDK_USER_ONRSPUSERLOGOUT                              = 20099;
//�û���¼�����͵ı���֪ͨ
const int AS_SDK_USER_ONRTNORDER_AFTER_LOGIN                       = 20100;
//�û���¼�����͵ĳɽ�֪ͨ
const int AS_SDK_USER_ONRTNTRADE_AFTER_LOGIN                       = 20101;
//�����ѯ����(���˻�)
const int AS_SDK_USER_REQQRYDEPTHMARKETDATA_MAIN_ACCOUNT           = 20102;
//��ʼ����
const int AS_SDK_USER_START_SETTLEMENT                             = 20103;
//Ͷ���߽�����ȷ�ϵ���Ӧ
const int AS_SDK_USER_ONRSPSETTLEMENTINFOCONFIRM                   = 20104;
//��ѯ������Ϣȷ�ϵ���Ӧ
const int AS_SDK_USER_ONRSPQRYSETTLEMENTINFOCONFIRM                = 20105;
//��ѯͶ���߽���������Ӧ
const int AS_SDK_USER_ONRSPQRYSETTLEMENTINFO                       = 20106;
//�������˻���ɽ���
const int AS_SDK_USER_SETTLEMENT_FINISH                            = 20107;

//�ͻ�����֤��Ӧ
const int AS_SDK_USER_ONRSPAUTHENTICATE                            = 20200;
//�û��������������Ӧ
const int AS_SDK_USER_ONRSPUSERPASSWORDUPDATE                      = 20201;
//�ʽ��˻��������������Ӧ
const int AS_SDK_USER_ONRSPTRADINGACCOUNTPASSWORDUPDATE            = 20202;
//Ԥ��¼��������Ӧ
const int AS_SDK_USER_ONRSPPARKEDORDERINSERT                       = 20203;
//Ԥ�񳷵�¼��������Ӧ
const int AS_SDK_USER_ONRSPPARKEDORDERACTION                       = 20204;
//��ѯ��󱨵�������Ӧ
const int AS_SDK_USER_ONRSPQUERYMAXORDERVOLUME                     = 20205;
//ɾ��Ԥ����Ӧ
const int AS_SDK_USER_ONRSPREMOVEPARKEDORDER                       = 20206;
//ɾ��Ԥ�񳷵���Ӧ
const int AS_SDK_USER_ONRSPREMOVEPARKEDORDERACTION                 = 20207;
//ִ������¼��������Ӧ
const int AS_SDK_USER_ONRSPEXECORDERINSERT                         = 20208;
//ִ���������������Ӧ
const int AS_SDK_USER_ONRSPEXECORDERACTION                         = 20209;
//ѯ��¼��������Ӧ
const int AS_SDK_USER_ONRSPFORQUOTEINSERT                          = 20210;
//����¼��������Ӧ
const int AS_SDK_USER_ONRSPQUOTEINSERT                             = 20211;
//���۲���������Ӧ
const int AS_SDK_USER_ONRSPQUOTEACTION                             = 20212;
//������������������Ӧ
const int AS_SDK_USER_ONRSPBATCHORDERACTION                        = 20213;
//��Ȩ�ԶԳ�¼��������Ӧ
const int AS_SDK_USER_ONRSPOPTIONSELFCLOSEINSERT                   = 20214;
//��Ȩ�ԶԳ����������Ӧ
const int AS_SDK_USER_ONRSPOPTIONSELFCLOSEACTION                   = 20215;
//�������¼��������Ӧ
const int AS_SDK_USER_ONRSPCOMBACTIONINSERT                        = 20216;
//�����ѯͶ������Ӧ
const int AS_SDK_USER_ONRSPQRYINVESTOR                             = 20217;
//�����ѯ���ױ�����Ӧ
const int AS_SDK_USER_ONRSPQRYTRADINGCODE                          = 20218;
//�����ѯ��Լ��֤������Ӧ
const int AS_SDK_USER_ONRSPQRYINSTRUMENTMARGINRATE                 = 20219;
//�����ѯ��Լ����������Ӧ
const int AS_SDK_USER_ONRSPQRYINSTRUMENTCOMMISSIONRATE             = 20220;
//�����ѯ��������Ӧ
const int AS_SDK_USER_ONRSPQRYEXCHANGE                             = 20221;
//�����ѯ��Ʒ��Ӧ
const int AS_SDK_USER_ONRSPQRYPRODUCT                              = 20222;
//�����ѯ������Ӧ
const int AS_SDK_USER_ONRSPQRYDEPTHMARKETDATA                      = 20223;
//�����ѯת��������Ӧ
const int AS_SDK_USER_ONRSPQRYTRANSFERBANK                         = 20224;
//�����ѯ�ͻ�֪ͨ��Ӧ
const int AS_SDK_USER_ONRSPQRYNOTICE                               = 20225;
//�����ѯͶ���ֲ߳���ϸ��Ӧ(��ϳֲ���ϸ)
const int AS_SDK_USER_ONRSPQRYINVESTORPOSITIONCOMBINEDETAIL        = 20226;
//��ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ��Ӧ
const int AS_SDK_USER_ONRSPQRYCFMMCTRADINGACCOUNTKEY               = 20227;
//�����ѯ�ֵ��۵���Ϣ��Ӧ
const int AS_SDK_USER_ONRSPQRYEWARRANTOFFSET                       = 20228;
//�����ѯͶ����Ʒ��/��Ʒ�ֱ�֤����Ӧ
const int AS_SDK_USER_ONRSPQRYINVESTORPRODUCTGROUPMARGIN           = 20229;
//�����ѯ��������֤������Ӧ
const int AS_SDK_USER_ONRSPQRYEXCHANGEMARGINRATE                   = 20230;
//�����ѯ������������֤������Ӧ
const int AS_SDK_USER_ONRSPQRYEXCHANGEMARGINRATEADJUST             = 20231;
//�����ѯ������Ӧ
const int AS_SDK_USER_ONRSPQRYEXCHANGERATE                         = 20232;
//�����ѯ�����������Ա����Ȩ����Ӧ
const int AS_SDK_USER_ONRSPQRYSECAGENTACIDMAP                      = 20233;
//�����ѯ��Ʒ���ۻ���
const int AS_SDK_USER_ONRSPQRYPRODUCTEXCHRATE                      = 20234;
//�����ѯ��Ʒ��
const int AS_SDK_USER_ONRSPQRYPRODUCTGROUP                         = 20235;
//�����ѯ�����̺�Լ����������Ӧ
const int AS_SDK_USER_ONRSPQRYMMINSTRUMENTCOMMISSIONRATE           = 20236;
//�����ѯ��������Ȩ��Լ��������Ӧ
const int AS_SDK_USER_ONRSPQRYMMOPTIONINSTRCOMMRATE                = 20237;
//�����ѯ������������Ӧ
const int AS_SDK_USER_ONRSPQRYINSTRUMENTORDERCOMMRATE              = 20238;
//�����ѯ�ʽ��˻���Ӧ
const int AS_SDK_USER_ONRSPQRYSECAGENTTRADINGACCOUNT               = 20239;
//�����ѯ�����������ʽ�У��ģʽ��Ӧ
const int AS_SDK_USER_ONRSPQRYSECAGENTCHECKMODE                    = 20240;
//�����ѯ��Ȩ���׳ɱ���Ӧ
const int AS_SDK_USER_ONRSPQRYOPTIONINSTRTRADECOST                 = 20241;
//�����ѯ��Ȩ��Լ��������Ӧ
const int AS_SDK_USER_ONRSPQRYOPTIONINSTRCOMMRATE                  = 20242;
//�����ѯִ��������Ӧ
const int AS_SDK_USER_ONRSPQRYEXECORDER                            = 20243;
//�����ѯѯ����Ӧ
const int AS_SDK_USER_ONRSPQRYFORQUOTE                             = 20244;
//�����ѯ������Ӧ
const int AS_SDK_USER_ONRSPQRYQUOTE                                = 20245;
//�����ѯ��Ȩ�ԶԳ���Ӧ
const int AS_SDK_USER_ONRSPQRYOPTIONSELFCLOSE                      = 20246;
//�����ѯͶ�ʵ�Ԫ��Ӧ
const int AS_SDK_USER_ONRSPQRYINVESTUNIT                           = 20247;
//�����ѯ��Ϻ�Լ��ȫϵ����Ӧ
const int AS_SDK_USER_ONRSPQRYCOMBINSTRUMENTGUARD                  = 20248;
//�����ѯ���������Ӧ
const int AS_SDK_USER_ONRSPQRYCOMBACTION                           = 20249;
//�����ѯת����ˮ��Ӧ
const int AS_SDK_USER_ONRSPQRYTRANSFERSERIAL                       = 20250;
//�����ѯ����ǩԼ��ϵ��Ӧ
const int AS_SDK_USER_ONRSPQRYACCOUNTREGISTER                      = 20251;
//����Ӧ��
const int AS_SDK_USER_ONRSPERROR                                   = 20252;
//����¼�����ر�
const int AS_SDK_USER_ONERRRTNORDERINSERT                          = 20253;
//������������ر�
const int AS_SDK_USER_ONERRRTNORDERACTION                          = 20254;
//��Լ����״̬֪ͨ
const int AS_SDK_USER_ONRTNINSTRUMENTSTATUS                        = 20255;
//����������֪ͨ
const int AS_SDK_USER_ONRTNBULLETIN                                = 20256;
//����֪ͨ
const int AS_SDK_USER_ONRTNTRADINGNOTICE                           = 20257;
//��ʾ������У�����
const int AS_SDK_USER_ONRTNERRORCONDITIONALORDER                   = 20258;
//ִ������֪ͨ
const int AS_SDK_USER_ONRTNEXECORDER                               = 20259;
//ִ������¼�����ر�
const int AS_SDK_USER_ONERRRTNEXECORDERINSERT                      = 20260;
//ִ�������������ر�
const int AS_SDK_USER_ONERRRTNEXECORDERACTION                      = 20261;
//ѯ��¼�����ر�
const int AS_SDK_USER_ONERRRTNFORQUOTEINSERT                       = 20262;
//����֪ͨ
const int AS_SDK_USER_ONRTNQUOTE                                   = 20263;
//����¼�����ر�
const int AS_SDK_USER_ONERRRTNQUOTEINSERT                          = 20264;
//���۲�������ر�
const int AS_SDK_USER_ONERRRTNQUOTEACTION                          = 20265;
//ѯ��֪ͨ
const int AS_SDK_USER_ONRTNFORQUOTERSP                             = 20266;
//��֤���������û�����
const int AS_SDK_USER_ONRTNCFMMCTRADINGACCOUNTTOKEN                = 20267;
//����������������ر�
const int AS_SDK_USER_ONERRRTNBATCHORDERACTION                     = 20268;
//��Ȩ�ԶԳ�֪ͨ
const int AS_SDK_USER_ONRTNOPTIONSELFCLOSE                         = 20269;
//��Ȩ�ԶԳ�¼�����ر�
const int AS_SDK_USER_ONERRRTNOPTIONSELFCLOSEINSERT                = 20270;
//��Ȩ�ԶԳ��������ر�
const int AS_SDK_USER_ONERRRTNOPTIONSELFCLOSEACTION                = 20271;
//�������֪ͨ
const int AS_SDK_USER_ONRTNCOMBACTION                              = 20272;
//�������¼�����ر�
const int AS_SDK_USER_ONERRRTNCOMBACTIONINSERT                     = 20273;
//�����ѯǩԼ������Ӧ
const int AS_SDK_USER_ONRSPQRYCONTRACTBANK                         = 20274;
//�����ѯԤ����Ӧ
const int AS_SDK_USER_ONRSPQRYPARKEDORDER                          = 20275;
//�����ѯԤ�񳷵���Ӧ
const int AS_SDK_USER_ONRSPQRYPARKEDORDERACTION                    = 20276;
//�����ѯ����֪ͨ��Ӧ
const int AS_SDK_USER_ONRSPQRYTRADINGNOTICE                        = 20277;
//�����ѯ���͹�˾���ײ�����Ӧ
const int AS_SDK_USER_ONRSPQRYBROKERTRADINGPARAMS                  = 20278;
//�����ѯ���͹�˾�����㷨��Ӧ
const int AS_SDK_USER_ONRSPQRYBROKERTRADINGALGOS                   = 20279;
//�����ѯ��������û�����
const int AS_SDK_USER_ONRSPQUERYCFMMCTRADINGACCOUNTTOKEN           = 20280;
//���з��������ʽ�ת�ڻ�֪ͨ
const int AS_SDK_USER_ONRTNFROMBANKTOFUTUREBYBANK                  = 20281;
//���з����ڻ��ʽ�ת����֪ͨ
const int AS_SDK_USER_ONRTNFROMFUTURETOBANKBYBANK                  = 20282;
//���з����������ת�ڻ�֪ͨ
const int AS_SDK_USER_ONRTNREPEALFROMBANKTOFUTUREBYBANK            = 20283;
//���з�������ڻ�ת����֪ͨ
const int AS_SDK_USER_ONRTNREPEALFROMFUTURETOBANKBYBANK            = 20284;
//�ڻ����������ʽ�ת�ڻ�֪ͨ
const int AS_SDK_USER_ONRTNFROMBANKTOFUTUREBYFUTURE                = 20285;
//�ڻ������ڻ��ʽ�ת����֪ͨ
const int AS_SDK_USER_ONRTNFROMFUTURETOBANKBYFUTURE                = 20286;
//ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
const int AS_SDK_USER_ONRTNREPEALFROMBANKTOFUTUREBYFUTUREMANUAL    = 20287;
//ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
const int AS_SDK_USER_ONRTNREPEALFROMFUTURETOBANKBYFUTUREMANUAL    = 20288;
//�ڻ������ѯ�������֪ͨ
const int AS_SDK_USER_ONRTNQUERYBANKBALANCEBYFUTURE                = 20289;
//�ڻ����������ʽ�ת�ڻ�����ر�
const int AS_SDK_USER_ONERRRTNBANKTOFUTUREBYFUTURE                 = 20290;
//�ڻ������ڻ��ʽ�ת���д���ر�
const int AS_SDK_USER_ONERRRTNFUTURETOBANKBYFUTURE                 = 20291;
//ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ�����ر�
const int AS_SDK_USER_ONERRRTNREPEALBANKTOFUTUREBYFUTUREMANUAL     = 20292;
//ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת���д���ر�
const int AS_SDK_USER_ONERRRTNREPEALFUTURETOBANKBYFUTUREMANUAL     = 20293;
//�ڻ������ѯ����������ر�
const int AS_SDK_USER_ONERRRTNQUERYBANKBALANCEBYFUTURE             = 20294;
//�ڻ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
const int AS_SDK_USER_ONRTNREPEALFROMBANKTOFUTUREBYFUTURE          = 20295;
//�ڻ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
const int AS_SDK_USER_ONRTNREPEALFROMFUTURETOBANKBYFUTURE          = 20296;
//�ڻ����������ʽ�ת�ڻ�Ӧ��
const int AS_SDK_USER_ONRSPFROMBANKTOFUTUREBYFUTURE                = 20297;
//�ڻ������ڻ��ʽ�ת����Ӧ��
const int AS_SDK_USER_ONRSPFROMFUTURETOBANKBYFUTURE                = 20298;
//�ڻ������ѯ�������Ӧ��
const int AS_SDK_USER_ONRSPQUERYBANKACCOUNTMONEYBYFUTURE           = 20399;
//���з������ڿ���֪ͨ
const int AS_SDK_USER_ONRTNOPENACCOUNTBYBANK                       = 20300;
//���з�����������֪ͨ
const int AS_SDK_USER_ONRTNCANCELACCOUNTBYBANK                     = 20301;
//���з����������˺�֪ͨ
const int AS_SDK_USER_ONRTNCHANGEACCOUNTBYBANK                     = 20302;
const int AS_SDK_USER_HEARTBEAT                     = 20500;
//��������
const int AS_SDK_ONRTNDEPTHMARKETDATA                              = 30001;

#endif
