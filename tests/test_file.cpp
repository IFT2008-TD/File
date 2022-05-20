//
// Created by etudiant on 22-05-20.
//

#include "File.h"
#include "gtest/gtest.h"

TEST(File, constructeur_defaut_noexcept) {
    EXPECT_NO_THROW(td4::File<int> maFile) ;
}

TEST(File, constructeur_liste_noexcept) {
    EXPECT_NO_THROW(td4::File<int> maFile ({1, 2, 3})) ;
}

class FileTest : public ::testing::Test {
protected:

    td4::File<int> file_vide ;
    td4::File<int> file_5 {100, 200, 300, 400, 500} ;
};

TEST_F(FileTest, estVide_true_file_vide) {
    EXPECT_TRUE(file_vide.estVide()) ;
}

TEST_F(FileTest, estVide_false_file_non_vide) {
    EXPECT_FALSE(file_5.estVide()) ;
}