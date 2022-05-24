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

TEST(File, constructeur_cap_depasse_cap_max_throw) {
    EXPECT_THROW(td4::File<int> maFile(td4::File<int>::cap_maximum + 1), std::invalid_argument) ;
}

class FileTest : public ::testing::Test {
protected:

    td4::File<int> file_vide ;
    td4::File<int> file_5 {100, 200, 300, 400, 500} ;
};

TEST_F(FileTest, estVide_true_file_vide) {
    EXPECT_TRUE(file_vide.estVide()) ;
}

TEST_F(FileTest, capacite_file_vide_egal_cap_defaut) {
    size_t attendu = td4::File<int>::cap_defaut ;
    EXPECT_EQ(attendu, file_vide.disponible()) ;
}

TEST_F(FileTest, estVide_false_file_non_vide) {
    EXPECT_FALSE(file_5.estVide()) ;
}

TEST_F(FileTest, estPleine_false_file_5) {
    EXPECT_FALSE(file_5.estPleine()) ;
}

TEST_F(FileTest, capacite_file_5_egal_5) {
    EXPECT_EQ(5, file_5.disponible()) ;
}

TEST_F(FileTest, enfiler_disponible_diminue_de_1) {
    file_vide.enfiler(1) ;
    EXPECT_EQ(td4::File<int>::cap_defaut - 1, file_vide.disponible()) ;
}

TEST_F(FileTest, enfiler_file_vide_n_est_plus_vide) {
    file_vide.enfiler(1) ;
    EXPECT_FALSE(file_vide.estVide()) ;
}

TEST_F(FileTest, enfiler_file_vide_defile_le_meme_element) {
    file_vide.enfiler(1) ;
    EXPECT_EQ(1, file_vide.premier()) ;
}