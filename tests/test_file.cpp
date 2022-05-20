//
// Created by etudiant on 22-05-20.
//

#include "File.h"
#include "gtest/gtest.h"

TEST(File, constructeur_defaut_noexcept) {
    EXPECT_NO_THROW(File<int> maFile) ;
}
