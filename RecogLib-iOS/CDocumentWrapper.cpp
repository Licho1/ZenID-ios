//
//  CDocumentWrapper.cpp
//  RecogLib-iOS
//
//  Created by Marek Stana on 26/06/2019.
//  Copyright © 2019 Marek Stana. All rights reserved.
//

#include "include/CDocumentWrapper.hpp"
#include "./include/DocumentPictureVerifier.h"

#include <string>

const void * initializeListWrapper(void *object) {
    std::string &a = *reinterpret_cast<std::string*>(object);
    RecogLibC::DocumentPictureVerifier *list = new RecogLibC::DocumentPictureVerifier(a);
    return (void *)list;
}

bool load(const void *object) {
    RecogLibC::DocumentPictureVerifier *iterator = (RecogLibC::DocumentPictureVerifier *)object;
    printf("loading");
    return true;
}

bool verify(const void *object) {
    RecogLibC::DocumentPictureVerifier *iterator = (RecogLibC::DocumentPictureVerifier *)object;
    return false;
}


