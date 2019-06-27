//
//  CDocumentWrapper.hpp
//  RecogLib-iOS
//
//  Created by Marek Stana on 26/06/2019.
//  Copyright © 2019 Marek Stana. All rights reserved.
//

#ifndef CDocumentWrapper_hpp
#define CDocumentWrapper_hpp

#include <stdio.h>
#include <string.h>
#include <CoreMedia/CoreMedia.h>
#include "MatcherResult.h"

#ifdef __cplusplus
extern "C" {
#endif

const void * loadWrapper(const char * path);
CMatcherResult* verify(const void *object, CMSampleBufferRef _mat, float _horizontalMargin, float _verticalMargin, int _documentRole, int _country, int _pageCode);

#ifdef __cplusplus
}
#endif

#endif /* CDocumentWrapper_hpp */
