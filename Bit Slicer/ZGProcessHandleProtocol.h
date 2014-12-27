/*
 * Created by Mayur Pawashe on 12/26/14.
 *
 * Copyright (c) 2014 zgcoder
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * Neither the name of the project's author nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import "ZGMemoryTypes.h"
#import "ZGVariableTypes.h"

@class ZGProcess;
@class ZGRegion;

@protocol ZGProcessHandleProtocol <NSObject>

- (id)initWithProcessTask:(ZGMemoryMap)processTask;

- (BOOL)allocateMemoryAndGetAddress:(ZGMemoryAddress *)address size:(ZGMemorySize)size;
- (BOOL)deallocateMemoryAtAddress:(ZGMemoryAddress)address size:(ZGMemorySize)size;

- (BOOL)readBytes:(void **)bytes address:(ZGMemoryAddress)address size:(ZGMemorySize *)size;
- (BOOL)freeBytes:(const void *)bytes size:(ZGMemorySize)size;

- (BOOL)writeBytes:(const void *)bytes address:(ZGMemoryAddress)address size:(ZGMemorySize)size;
- (BOOL)writeBytesOverwritingProtection:(const void *)bytes address:(ZGMemoryAddress)address size:(ZGMemorySize)size;
- (BOOL)writeBytesIgnoringProtection:(const void *)bytes address:(ZGMemoryAddress)address size:(ZGMemorySize)size;

- (BOOL)getTaskInfo:(void *)taskInfo flavor:(task_flavor_t)flavor count:(mach_msg_type_number_t *)count;

- (BOOL)setProtection:(ZGMemoryProtection)protection address:(ZGMemoryAddress)address size:(ZGMemorySize)size;

- (BOOL)getPageSize:(ZGMemorySize *)pageSize;

- (BOOL)suspend;
- (BOOL)resume;
- (BOOL)getSuspendCount:(integer_t *)suspendCount;

- (NSArray *)regions;
- (NSArray *)submapRegions;
- (NSArray *)submapRegionsInRegion:(ZGRegion *)region;

- (BOOL)getRegionInfo:(ZGMemoryBasicInfo *)regionInfo address:(ZGMemoryAddress *)address size:(ZGMemorySize *)size;
- (BOOL)getMemoryProtection:(ZGMemoryProtection *)memoryProtection address:(ZGMemoryAddress *)address size:(ZGMemorySize *)size;

- (NSString *)symbolAtAddress:(ZGMemoryAddress)address relativeOffset:(ZGMemoryAddress *)relativeOffset;
- (NSNumber *)findSymbol:(NSString *)symbolName withPartialSymbolOwnerName:(NSString *)partialSymbolOwnerName requiringExactMatch:(BOOL)requiresExactMatch pastAddress:(ZGMemoryAddress)pastAddress;

- (ZGMemorySize)readStringSizeFromAddress:(ZGMemoryAddress)address dataType:(ZGVariableType)dataType oldSize:(ZGMemorySize)oldSize maxSize:(ZGMemorySize)maxStringSizeLimit;

@end