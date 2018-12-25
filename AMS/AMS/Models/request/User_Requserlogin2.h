//登录请求2
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface User_Requserlogin2 : NSObject
@property(nonatomic,copy) NSString *TradingDay;//交易日
@property(nonatomic,copy) NSString *BrokerID;//经纪公司代码
@property(nonatomic,copy) NSString *UserID;//用户代码
@property(nonatomic,copy) NSString *Password;//密码
@property(nonatomic,copy) NSString *UserProductInfo;//用户端产品信息
@property(nonatomic,copy) NSString *InterfaceProductInfo;//接口端产品信息
@property(nonatomic,copy) NSString *ProtocolInfo;//协议信息
@property(nonatomic,copy) NSString *MacAddress;//Mac地址
@property(nonatomic,copy) NSString *OneTimePassword;//动态密码
@property(nonatomic,copy) NSString *ClientIPAddress;//终端IP地址
@property(nonatomic,copy) NSString *LoginRemark;//登录备注
@property(nonatomic,strong) NSNumber *nRequestID;//请求的编号

NS_ASSUME_NONNULL_END
@end