//请求删除预埋撤单
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface User_Reqremoveparkedorderaction : NSObject
@property(nonatomic,copy) NSString *BrokerID;//经纪公司代码
@property(nonatomic,copy) NSString *InvestorID;//投资者代码
@property(nonatomic,copy) NSString *ParkedOrderActionID;//预埋撤单编号
@property(nonatomic,copy) NSString *InvestUnitID;//投资单元代码
@property(nonatomic,strong) NSNumber *nRequestID;//请求的编号

NS_ASSUME_NONNULL_END
@end