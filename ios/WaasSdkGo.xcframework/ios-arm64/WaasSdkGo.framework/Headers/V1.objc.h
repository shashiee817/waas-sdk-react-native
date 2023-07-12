//
// File is generated by gobind. Do not edit.

#ifndef __V1_H__
#define __V1_H__

@import Foundation;
#include "ref.h"
#include "Universe.objc.h"


@class V1AddDeviceOperation;
@class V1Address;
@class V1CreateDeviceGroupOperation;
@class V1CreateMPCWalletResponse;
@class V1CreateSignatureOperation;
@class V1Device;
@class V1DeviceGroup;
@class V1ExportPrivateKeysResponse;
@class V1MPCWallet;
@class V1Pool;
@class V1PrepareDeviceArchiveOperation;
@class V1PrepareDeviceBackupOperation;
@class V1Signature;
@class V1SignedTransaction;
@class V1Transaction;
@protocol V1AndroidCallbacks;
@class V1AndroidCallbacks;
@protocol V1ApiResponseReceiver;
@class V1ApiResponseReceiver;
@protocol V1MPCKeyService;
@class V1MPCKeyService;
@protocol V1MPCSdk;
@class V1MPCSdk;
@protocol V1MPCWalletService;
@class V1MPCWalletService;
@protocol V1PoolService;
@class V1PoolService;

@protocol V1AndroidCallbacks <NSObject>
@end

@protocol V1ApiResponseReceiver <NSObject>
- (void)returnValue:(NSString* _Nullable)data err:(NSError* _Nullable)err;
@end

@protocol V1MPCKeyService <NSObject>
- (void)addDevice:(NSString* _Nullable)deviceGroup device:(NSString* _Nullable)device receiver:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (void)createTxSignature:(NSString* _Nullable)keyName tx:(NSData* _Nullable)tx receiver:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (V1DeviceGroup* _Nullable)getDeviceGroup:(NSString* _Nullable)deviceGroupName error:(NSError* _Nullable* _Nullable)error;
- (V1SignedTransaction* _Nullable)getSignedTransaction:(NSData* _Nullable)tx signature:(V1Signature* _Nullable)signature error:(NSError* _Nullable* _Nullable)error;
- (NSData* _Nullable)pollPendingDeviceArchives:(NSString* _Nullable)deviceGroup pollInterval:(int64_t)pollInterval error:(NSError* _Nullable* _Nullable)error;
- (NSData* _Nullable)pollPendingDeviceBackups:(NSString* _Nullable)deviceGroup pollInterval:(int64_t)pollInterval error:(NSError* _Nullable* _Nullable)error;
- (NSData* _Nullable)pollPendingDeviceGroup:(NSString* _Nullable)deviceGroup pollInterval:(int64_t)pollInterval error:(NSError* _Nullable* _Nullable)error;
- (NSData* _Nullable)pollPendingDevices:(NSString* _Nullable)deviceGroup pollInterval:(int64_t)pollInterval error:(NSError* _Nullable* _Nullable)error;
- (NSData* _Nullable)pollPendingSignatures:(NSString* _Nullable)deviceGroup pollInterval:(int64_t)pollInterval error:(NSError* _Nullable* _Nullable)error;
- (void)prepareDeviceArchive:(NSString* _Nullable)deviceGroup device:(NSString* _Nullable)device receiver:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (void)prepareDeviceBackup:(NSString* _Nullable)deviceGroup device:(NSString* _Nullable)device receiver:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (V1Device* _Nullable)registerDevice:(NSError* _Nullable* _Nullable)error;
- (void)stopPollingPendingDeviceArchives:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (void)stopPollingPendingDeviceBackups:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (void)stopPollingPendingDeviceGroup:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (void)stopPollingPendingDevices:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (void)stopPollingPendingSignatures:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (V1Signature* _Nullable)waitPendingSignature:(NSString* _Nullable)operation error:(NSError* _Nullable* _Nullable)error;
@end

@protocol V1MPCSdk <NSObject>
- (void)bootstrapDevice:(NSString* _Nullable)passcode receiver:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (BOOL)computeAddDeviceMPCOperation:(NSString* _Nullable)mpcData passcode:(NSString* _Nullable)passcode deviceBackup:(NSString* _Nullable)deviceBackup error:(NSError* _Nullable* _Nullable)error;
- (BOOL)computeMPCOperation:(NSString* _Nullable)mpcData error:(NSError* _Nullable* _Nullable)error;
- (BOOL)computePrepareDeviceArchiveMPCOperation:(NSString* _Nullable)mpcData passcode:(NSString* _Nullable)passcode error:(NSError* _Nullable* _Nullable)error;
- (BOOL)computePrepareDeviceBackupMPCOperation:(NSString* _Nullable)mpcData passcode:(NSString* _Nullable)passcode error:(NSError* _Nullable* _Nullable)error;
- (void)exportDeviceBackup:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (NSData* _Nullable)exportPrivateKeys:(NSString* _Nullable)mpcKeyExportMetadata passcode:(NSString* _Nullable)passcode error:(NSError* _Nullable* _Nullable)error;
- (void)getRegistrationData:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (BOOL)resetPasscode:(NSString* _Nullable)newPasscode error:(NSError* _Nullable* _Nullable)error;
@end

@protocol V1MPCWalletService <NSObject>
- (V1CreateMPCWalletResponse* _Nullable)createMPCWallet:(NSString* _Nullable)parent device:(NSString* _Nullable)device error:(NSError* _Nullable* _Nullable)error;
- (NSData* _Nullable)generateAddress:(NSString* _Nullable)mpcWallet network:(NSString* _Nullable)network error:(NSError* _Nullable* _Nullable)error;
- (NSData* _Nullable)getAddress:(NSString* _Nullable)name error:(NSError* _Nullable* _Nullable)error;
- (V1MPCWallet* _Nullable)waitPendingMPCWallet:(NSString* _Nullable)operation error:(NSError* _Nullable* _Nullable)error;
@end

@protocol V1PoolService <NSObject>
- (V1Pool* _Nullable)createPool:(NSString* _Nullable)displayName poolID:(NSString* _Nullable)poolID error:(NSError* _Nullable* _Nullable)error;
@end

/**
 * AddDeviceOperation represents an MPCOperation for AddDevice.
 */
@interface V1AddDeviceOperation : NSObject <goSeqRefInterface, V1AndroidCallbacks> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * The resource name of the DeviceGroup.
Format: pools/{pool_id}/deviceGroups/{device_group_id}
 */
@property (nonatomic) NSString* _Nonnull deviceGroup;
/**
 * The resource name of the Operation adding the Device to the DeviceGroup.
The format: operations/{operation_id}
 */
@property (nonatomic) NSString* _Nonnull operation;
/**
 * The resource name of the MPCOperation.
Format: pools/{pool_id}/deviceGroups/{device_group_id}/mpcOperations/{mpc_operation_id}
 */
@property (nonatomic) NSString* _Nonnull mpcOperation;
/**
 * The MPCData associated with this operation. To process this operation, ComputeAddDeviceMPCOperation API
has to be invoked with this data.
Format: base64 encoded string.
 */
@property (nonatomic) NSString* _Nonnull mpcData;
@end

/**
 * Address represents a WaaS Address resource.
 */
@interface V1Address : NSObject <goSeqRefInterface, V1AndroidCallbacks> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull name;
@property (nonatomic) NSString* _Nonnull address;
// skipped field Address.MPCKeys with unsupported type: []string

@property (nonatomic) NSString* _Nonnull mpcWallet;
@end

/**
 * CreateDeviceGroupOperation represents an MPCOperation for CreateDeviceGroup.
 */
@interface V1CreateDeviceGroupOperation : NSObject <goSeqRefInterface, V1AndroidCallbacks> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * The resource name of the DeviceGroup.
Format: pools/{pool_id}/deviceGroups/{device_group_id}
 */
@property (nonatomic) NSString* _Nonnull deviceGroup;
/**
 * The resource name of the Operation creating this DeviceGroup.
The format: operations/{operation_id}
 */
@property (nonatomic) NSString* _Nonnull operation;
/**
 * The resource name of the MPCOperation.
Format: pools/{pool_id}/deviceGroups/{device_group_id}/mpcOperations/{mpc_operation_id}
 */
@property (nonatomic) NSString* _Nonnull mpcOperation;
/**
 * The MPCData associated with this operation. To process this operation, ComputeMPCOperation API has to be invoked with this data.
Format: base64 encoded string.
 */
@property (nonatomic) NSString* _Nonnull mpcData;
@end

/**
 * CreateMPCWalletResponse represents the Response of CreateMPCWalletRequest.
 */
@interface V1CreateMPCWalletResponse : NSObject <goSeqRefInterface, V1AndroidCallbacks> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull deviceGroup;
@property (nonatomic) NSString* _Nonnull operation;
@end

/**
 * CreateSignatureOperation represents an MPCOperation for CreateSignature.
 */
@interface V1CreateSignatureOperation : NSObject <goSeqRefInterface, V1AndroidCallbacks> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * The resource name of the DeviceGroup.
Format: pools/{pool_id}/deviceGroups/{device_group_id}
 */
@property (nonatomic) NSString* _Nonnull deviceGroup;
/**
 * The resource name of the Operation creating this DeviceGroup.
The format: operations/{operation_id}
 */
@property (nonatomic) NSString* _Nonnull operation;
/**
 * The resource name of the MPCOperation.
Format: pools/{pool_id}/deviceGroups/{device_group_id}/mpcOperations/{mpc_operation_id}
 */
@property (nonatomic) NSString* _Nonnull mpcOperation;
/**
 * The MPCData associated with this operation. To process this operation, ComputeMPCOperation API has to be invoked with this data.
Format: base64 encoded string.
 */
@property (nonatomic) NSString* _Nonnull mpcData;
/**
 * The Payload to sign as hex-encoded string.
 */
@property (nonatomic) NSString* _Nonnull payload;
@end

/**
 * Device represents a WaaS Device resource.
 */
@interface V1Device : NSObject <goSeqRefInterface, V1AndroidCallbacks> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * The resource name of the Device.
 */
@property (nonatomic) NSString* _Nonnull name;
@end

/**
 * DeviceGroup represents a WaaS DeviceGroup resource.
 */
@interface V1DeviceGroup : NSObject <goSeqRefInterface, V1AndroidCallbacks> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * The resource name of the DeviceGroup.
Format: pools/{pool_id}/deviceGroups/{device_group_id}
 */
@property (nonatomic) NSString* _Nonnull name;
/**
 * The metadata to be used to export MPCKeys derived from the Seed associated with the DeviceGroup.
This metadata has to be passed to the ExportPrivateKeys function to export private keys corresponding to
MPCKeys that are derived from the HardenedChildren of the Seed associated with the DeviceGroup.
Format: base64 encoded string.
 */
@property (nonatomic) NSString* _Nonnull mpcKeyExportMetadata;
/**
 * The list of Device resource names in this DeviceGroup.
Format: A byte array that can be unmarshalled into a string array.
 */
@property (nonatomic) NSData* _Nullable devices;
@end

/**
 * ExportPrivateKeysResponse represents the response to ExportPrivateKeys request.
 */
@interface V1ExportPrivateKeysResponse : NSObject <goSeqRefInterface, V1AndroidCallbacks> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * The 32 byte long elliptic curve private key of an MPCKey, as a non-prefixed hex string.
 */
@property (nonatomic) NSString* _Nonnull privateKey;
/**
 * The ethereum address as "0x"-prefixed hex string that corresponds to the exported private key.
Note: This is NOT a WaaS Address resource of the form
`networks/{networkID}/addresses/{addressID}.
 */
@property (nonatomic) NSString* _Nonnull address;
@end

/**
 * MPCWallet represents a WaaS MPCWallet resource.
 */
@interface V1MPCWallet : NSObject <goSeqRefInterface, V1AndroidCallbacks> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull name;
@property (nonatomic) NSString* _Nonnull deviceGroup;
@end

/**
 * Pool represents a WaaS Pool resource.
 */
@interface V1Pool : NSObject <goSeqRefInterface, V1AndroidCallbacks> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
@property (nonatomic) NSString* _Nonnull name;
@property (nonatomic) NSString* _Nonnull displayName;
@end

/**
 * PrepareDeviceArchiveOperation represents an MPCOperation for PrepareDeviceArchive.
 */
@interface V1PrepareDeviceArchiveOperation : NSObject <goSeqRefInterface, V1AndroidCallbacks> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * The resource name of the DeviceGroup.
Format: pools/{pool_id}/deviceGroups/{device_group_id}
 */
@property (nonatomic) NSString* _Nonnull deviceGroup;
/**
 * The resource name of the Operation creating this DeviceGroup.
The format: operations/{operation_id}
 */
@property (nonatomic) NSString* _Nonnull operation;
/**
 * The resource name of the MPCOperation.
Format: pools/{pool_id}/deviceGroups/{device_group_id}/mpcOperations/{mpc_operation_id}
 */
@property (nonatomic) NSString* _Nonnull mpcOperation;
/**
 * The MPCData associated with this operation. To process this operation, ComputeMPCOperation API has to be invoked with this data.
Format: base64 encoded string.
 */
@property (nonatomic) NSString* _Nonnull mpcData;
@end

/**
 * PrepareDeviceBackupOperation represents an MPCOperation for PrepareDeviceBackup.
 */
@interface V1PrepareDeviceBackupOperation : NSObject <goSeqRefInterface, V1AndroidCallbacks> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * The resource name of the DeviceGroup.
Format: pools/{pool_id}/deviceGroups/{device_group_id}
 */
@property (nonatomic) NSString* _Nonnull deviceGroup;
/**
 * The resource name of the Operation creating the Device backup.
The format: operations/{operation_id}
 */
@property (nonatomic) NSString* _Nonnull operation;
/**
 * The resource name of the MPCOperation.
Format: pools/{pool_id}/deviceGroups/{device_group_id}/mpcOperations/{mpc_operation_id}
 */
@property (nonatomic) NSString* _Nonnull mpcOperation;
/**
 * The MPCData associated with this operation. To process this operation, ComputePrepareDeviceBackupMPCOperation API
has to be invoked with this data.
Format: base64 encoded string.
 */
@property (nonatomic) NSString* _Nonnull mpcData;
@end

/**
 * Signature represents a WaaS Signature resource.
 */
@interface V1Signature : NSObject <goSeqRefInterface, V1AndroidCallbacks> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * The resource name of the Signature.
 */
@property (nonatomic) NSString* _Nonnull name;
/**
 * The payload to sign. It is a hex-encoded string.
 */
@property (nonatomic) NSString* _Nonnull payload;
/**
 * The signed payload. It is a hex-encoded string.
 */
@property (nonatomic) NSString* _Nonnull signedPayload;
@end

/**
 * SignedTransaction represents a signed transaction.
 */
@interface V1SignedTransaction : NSObject <goSeqRefInterface, V1AndroidCallbacks> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * Transaction represents the unsigned transaction.
 */
@property (nonatomic) V1Transaction* _Nullable transaction;
/**
 * Signature represents the signature of the signed transaction.
The Payload is the hash of the unsigned transaction, and the
SignedPayload is the 65-byte V, R, S value.
Both are hex strings.
 */
@property (nonatomic) V1Signature* _Nullable signature;
/**
 * RawTransaction is the RLP-encoded signed transaction.
It is a hex string that can be broadcast on-chain.
 */
@property (nonatomic) NSString* _Nonnull rawTransaction;
/**
 * TransactionHash is the hash of the signed transaction.
It is a hex string.
 */
@property (nonatomic) NSString* _Nonnull transactionHash;
@end

/**
 * Transaction represents an EIP-1559 transaction.
 */
@interface V1Transaction : NSObject <goSeqRefInterface, V1AndroidCallbacks> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (nonnull instancetype)init;
/**
 * The chain ID of the transaction as a "0x"-prefixed hex string.
 */
@property (nonatomic) NSString* _Nonnull chainID;
/**
 * The nonce of the transaction.
 */
@property (nonatomic) double nonce;
/**
 * The EIP-1559 maximum priority fee per gas as a "0x"-prefixed hex string.
 */
@property (nonatomic) NSString* _Nonnull maxPriorityFeePerGas;
/**
 * The EIP-1559 maximum fee per gas as a "0x"-prefixed hex string.
 */
@property (nonatomic) NSString* _Nonnull maxFeePerGas;
/**
 * The maximum amount of gas to use on the transaction.
 */
@property (nonatomic) double gas;
/**
 * The checksummed address to which the transaction is addressed, as a "0x"-prefixed hex string.
Note: This is NOT a WaaS Address resource of the form
`networks/{networkID}/addresses/{addressID}.
 */
@property (nonatomic) NSString* _Nonnull to;
/**
 * The native value of the transaction as a "0x"-prefixed hex string.
 */
@property (nonatomic) NSString* _Nonnull value;
/**
 * The hex-encoded data for the transaction.
 */
@property (nonatomic) NSString* _Nonnull data;
@end

/**
 * NewMPCKeyService returns a MPCKeyService from a given url.
 */
FOUNDATION_EXPORT id<V1MPCKeyService> _Nullable V1NewMPCKeyService(NSString* _Nullable mpcKeyServiceURL, NSString* _Nullable apiKeyName, NSString* _Nullable privateKey, NSError* _Nullable* _Nullable error);

/**
 * NewMPCSdk returns an instance of MPCSdk corresponding to the given url.
 */
FOUNDATION_EXPORT id<V1MPCSdk> _Nullable V1NewMPCSdk(NSString* _Nullable config, BOOL isSimulator, id<V1AndroidCallbacks> _Nullable callbacks, NSError* _Nullable* _Nullable error);

/**
 * NewMPCWalletService returns a MPCWalletService from a given url, Cloud API Key,
and private key.
 */
FOUNDATION_EXPORT id<V1MPCWalletService> _Nullable V1NewMPCWalletService(NSString* _Nullable url, NSString* _Nullable apiKeyName, NSString* _Nullable privateKey, NSError* _Nullable* _Nullable error);

/**
 * NewPoolService returns a PoolService from a given url, Cloud APIKey name,
and private key.
 */
FOUNDATION_EXPORT id<V1PoolService> _Nullable V1NewPoolService(NSString* _Nullable url, NSString* _Nullable apiKeyName, NSString* _Nullable privateKey, NSError* _Nullable* _Nullable error);

@class V1AndroidCallbacks;

@class V1ApiResponseReceiver;

@class V1MPCKeyService;

@class V1MPCSdk;

@class V1MPCWalletService;

@class V1PoolService;

/**
 * AndroidCallbacks is the interface to implement by Native Android code.
 */
@interface V1AndroidCallbacks : NSObject <goSeqRefInterface, V1AndroidCallbacks> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
@end

/**
 * ApiResponseReceiver represents the interface to get the return values of a method.
NOTE: gomobile can't return (string,error) back to native code on arm64 platforms.
 */
@interface V1ApiResponseReceiver : NSObject <goSeqRefInterface, V1ApiResponseReceiver> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (void)returnValue:(NSString* _Nullable)data err:(NSError* _Nullable)err;
@end

/**
 * MPCKeyService is the interface for the WaaS MPCKeyService that is exposed to native code.
 */
@interface V1MPCKeyService : NSObject <goSeqRefInterface, V1MPCKeyService> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (void)addDevice:(NSString* _Nullable)deviceGroup device:(NSString* _Nullable)device receiver:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (void)createTxSignature:(NSString* _Nullable)keyName tx:(NSData* _Nullable)tx receiver:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (V1DeviceGroup* _Nullable)getDeviceGroup:(NSString* _Nullable)deviceGroupName error:(NSError* _Nullable* _Nullable)error;
- (V1SignedTransaction* _Nullable)getSignedTransaction:(NSData* _Nullable)tx signature:(V1Signature* _Nullable)signature error:(NSError* _Nullable* _Nullable)error;
- (NSData* _Nullable)pollPendingDeviceArchives:(NSString* _Nullable)deviceGroup pollInterval:(int64_t)pollInterval error:(NSError* _Nullable* _Nullable)error;
- (NSData* _Nullable)pollPendingDeviceBackups:(NSString* _Nullable)deviceGroup pollInterval:(int64_t)pollInterval error:(NSError* _Nullable* _Nullable)error;
- (NSData* _Nullable)pollPendingDeviceGroup:(NSString* _Nullable)deviceGroup pollInterval:(int64_t)pollInterval error:(NSError* _Nullable* _Nullable)error;
- (NSData* _Nullable)pollPendingDevices:(NSString* _Nullable)deviceGroup pollInterval:(int64_t)pollInterval error:(NSError* _Nullable* _Nullable)error;
- (NSData* _Nullable)pollPendingSignatures:(NSString* _Nullable)deviceGroup pollInterval:(int64_t)pollInterval error:(NSError* _Nullable* _Nullable)error;
- (void)prepareDeviceArchive:(NSString* _Nullable)deviceGroup device:(NSString* _Nullable)device receiver:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (void)prepareDeviceBackup:(NSString* _Nullable)deviceGroup device:(NSString* _Nullable)device receiver:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (V1Device* _Nullable)registerDevice:(NSError* _Nullable* _Nullable)error;
- (void)stopPollingPendingDeviceArchives:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (void)stopPollingPendingDeviceBackups:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (void)stopPollingPendingDeviceGroup:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (void)stopPollingPendingDevices:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (void)stopPollingPendingSignatures:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (V1Signature* _Nullable)waitPendingSignature:(NSString* _Nullable)operation error:(NSError* _Nullable* _Nullable)error;
@end

/**
 * MPCSdk is the interface for the Device operations that is exposed to native code.
 */
@interface V1MPCSdk : NSObject <goSeqRefInterface, V1MPCSdk> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (void)bootstrapDevice:(NSString* _Nullable)passcode receiver:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (BOOL)computeAddDeviceMPCOperation:(NSString* _Nullable)mpcData passcode:(NSString* _Nullable)passcode deviceBackup:(NSString* _Nullable)deviceBackup error:(NSError* _Nullable* _Nullable)error;
- (BOOL)computeMPCOperation:(NSString* _Nullable)mpcData error:(NSError* _Nullable* _Nullable)error;
- (BOOL)computePrepareDeviceArchiveMPCOperation:(NSString* _Nullable)mpcData passcode:(NSString* _Nullable)passcode error:(NSError* _Nullable* _Nullable)error;
- (BOOL)computePrepareDeviceBackupMPCOperation:(NSString* _Nullable)mpcData passcode:(NSString* _Nullable)passcode error:(NSError* _Nullable* _Nullable)error;
- (void)exportDeviceBackup:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (NSData* _Nullable)exportPrivateKeys:(NSString* _Nullable)mpcKeyExportMetadata passcode:(NSString* _Nullable)passcode error:(NSError* _Nullable* _Nullable)error;
- (void)getRegistrationData:(id<V1ApiResponseReceiver> _Nullable)receiver;
- (BOOL)resetPasscode:(NSString* _Nullable)newPasscode error:(NSError* _Nullable* _Nullable)error;
@end

/**
 * MPCWalletService is the interface for the WaaS MPCWalletService that is exposed to native code.
 */
@interface V1MPCWalletService : NSObject <goSeqRefInterface, V1MPCWalletService> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (V1CreateMPCWalletResponse* _Nullable)createMPCWallet:(NSString* _Nullable)parent device:(NSString* _Nullable)device error:(NSError* _Nullable* _Nullable)error;
- (NSData* _Nullable)generateAddress:(NSString* _Nullable)mpcWallet network:(NSString* _Nullable)network error:(NSError* _Nullable* _Nullable)error;
- (NSData* _Nullable)getAddress:(NSString* _Nullable)name error:(NSError* _Nullable* _Nullable)error;
- (V1MPCWallet* _Nullable)waitPendingMPCWallet:(NSString* _Nullable)operation error:(NSError* _Nullable* _Nullable)error;
@end

/**
 * PoolService is the interface for the WaaS PoolService that is exposed to native code.
 */
@interface V1PoolService : NSObject <goSeqRefInterface, V1PoolService> {
}
@property(strong, readonly) _Nonnull id _ref;

- (nonnull instancetype)initWithRef:(_Nonnull id)ref;
- (V1Pool* _Nullable)createPool:(NSString* _Nullable)displayName poolID:(NSString* _Nullable)poolID error:(NSError* _Nullable* _Nullable)error;
@end

#endif
