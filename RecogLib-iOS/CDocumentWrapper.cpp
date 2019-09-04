//
//  CDocumentWrapper.cpp
//  RecogLib-iOS
//
//  Created by Marek Stana on 26/06/2019.
//  Copyright © 2019 Marek Stana. All rights reserved.
//

#include "CDocumentWrapper.hpp"
#include "RecogLibC.h"

#include "opencv2/opencv.hpp"

#include <CoreMedia/CoreMedia.h>

#include <string>

#define DEBUG_PRINT_ENABLED 0 // set to 1 to enable logging

const void * loadWrapper(const char *path)
{
    RecogLibC::DocumentPictureVerifier *verifier = new RecogLibC::DocumentPictureVerifier(path);
    printf("[Recoglib] loaded!");
    return (void *)verifier;
}

bool verify(
    const void *object,
    CMSampleBufferRef _mat,
    CDocumentInfo *document,
    float _horizontalMargin,
    float _verticalMargin
)
{
    CVImageBufferRef cvBuffer = CMSampleBufferGetImageBuffer(_mat);
    return verifyImage(object, cvBuffer, document, _horizontalMargin, _verticalMargin);
}

bool verifyImage(
            const void *object,
            CVPixelBufferRef _cvBuffer,
            CDocumentInfo *document,
            float _horizontalMargin,
            float _verticalMargin
            )
{
    RecogLibC::DocumentPictureVerifier *verifier = (RecogLibC::DocumentPictureVerifier *)object;
    
    float verticalMargin = _verticalMargin;
    float horizontalMargin = _horizontalMargin;
    
    // Construct outline
    const std::array<cv::Point2f, 4> expectedOutline {
        {
            {horizontalMargin, verticalMargin},
            {1.f - horizontalMargin, verticalMargin},
            {1.f - horizontalMargin, 1.f - verticalMargin},
            {horizontalMargin, 1.f - verticalMargin},
        }
    };
    
    // Construct optional data
    auto documentRole = static_cast<RecogLibC::DocumentRole>(document->role);
    auto country = static_cast<RecogLibC::Country>(document->country);
    auto pageCode = static_cast<RecogLibC::PageCodes>(document->page);
    
#if DEBUG_PRINT_ENABLED
    printf("[DEBUG-Recoglib-CONVERT] starts");
#endif
    CVPixelBufferLockBaseAddress( _cvBuffer, 0 );
    int widht = (int)CVPixelBufferGetWidth(_cvBuffer);
    int height = (int)CVPixelBufferGetHeight(_cvBuffer);
    
#if DEBUG_PRINT_ENABLED
    printf("[DEBUG-Recoglib-CONVERT] ends\n");
#endif
    
#if DEBUG_PRINT_ENABLED
    printf("[DEBUG-Recoglib-VERIFY] start\n");
#endif
    
    OSType format = CVPixelBufferGetPixelFormatType(_cvBuffer);
    
    cv::Mat image;
    if (format == kCVPixelFormatType_32BGRA) {
        image = cv::Mat(height, widht, CV_8UC4, CVPixelBufferGetBaseAddress(_cvBuffer), 0);
    } else {
        assert(false);
        printf("Unsupported format for CVPixelBufferGetPixelFormatType");
    }
#if DEBUG_PRINT_ENABLED
    printf("[DEBUG-Recoglib-CONVERT] ends");
#endif
#if DEBUG_PRINT_ENABLED
    printf("[DEBUG-Recoglib-VERIFY] start");
#endif
    verifier->ProcessFrame(image, expectedOutline, documentRole, country, pageCode);
    
    CVPixelBufferUnlockBaseAddress( _cvBuffer, 0 );
    
    const auto state = verifier->GetState();
    
    if (state == RecogLibC::DocumentPictureVerifier::State::NoMatchFound) {
        document->code = -1;
        document->state = static_cast<int>(state);
        return false;
    }
    
    document->code = static_cast<int>(verifier->GetDocumentCode());
    document->page = static_cast<int>(verifier->GetPageCode());
    document->state = static_cast<int>(state);
    
    return true;
}
