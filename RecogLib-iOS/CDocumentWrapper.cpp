//
//  CDocumentWrapper.cpp
//  RecogLib-iOS
//
//  Created by Marek Stana on 26/06/2019.
//  Copyright © 2019 Marek Stana. All rights reserved.
//

#include "include/CDocumentWrapper.hpp"
#include "./include/ZenidEnums.generated.h"
#include "./include/DocumentPictureVerifier.h"

#include "opencv2/opencv.hpp"

#include <string>

const void * loadWrapper(const char *path)
{
    RecogLibC::DocumentPictureVerifier *verifier = new RecogLibC::DocumentPictureVerifier(path);
    printf("[DEBUG-DOCUMENT] created!");
    return (void *)verifier;
}

bool verify(const void *object,
            long _mat,
            float _horizontalMargin,
            float _verticalMargin,
            int _documentRole,
            int _country,
            int _pageCode)
{
    RecogLibC::DocumentPictureVerifier *verifier = (RecogLibC::DocumentPictureVerifier *)object;

    float verticalMargin = _verticalMargin;
    float horizontalMargin = _horizontalMargin;
    printf("[DEBUG-DOCUMENT-VERIFY] horizontalMargin: %f, verticalMargin: %f", horizontalMargin, verticalMargin);


    // Construct outline
    const std::array<cv::Point2f, 4> expectedOutline{
        {
            {horizontalMargin, verticalMargin},
            {1.f - horizontalMargin, verticalMargin},
            {1.f - horizontalMargin, 1.f - verticalMargin},
            {horizontalMargin, 1.f - verticalMargin},
        }
    };

    // Construct optional data
    auto documentRole = static_cast<RecogLibC::DocumentRole>(_documentRole);
    auto country = static_cast<RecogLibC::Country>(_country);
    auto pageCode = static_cast<RecogLibC::PageCodes>(_pageCode);
    printf("[DEBUG-DOCUMENT-VERIFY] documentRole: %i, pageCode: %i, country: %i", (int) documentRole, (int) pageCode, (int) country);

    // Construct image
    const cv::Mat &image = *(cv::Mat *) _mat;

    verifier->ProcessFrame(image, expectedOutline, documentRole, country, pageCode);
    const auto state = verifier->GetState();

    printf("[DEBUG-DOCUMENT-VERIFY] verifier state: %i", state);

    return true;
}




