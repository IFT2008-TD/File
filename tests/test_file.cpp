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
    td4::File<int> file_2 {1, 2};
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

TEST_F(FileTest, capacite_file_5_egal_2_fois_5) {
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

TEST_F(FileTest, defiler_file_5_defile_dans_le_bon_ordre) {
    EXPECT_EQ(100, file_5.premier()) ;
    file_5.defiler() ;
    EXPECT_EQ(200, file_5.premier()) ;
    file_5.defiler() ;
    EXPECT_EQ(300, file_5.premier()) ;
    file_5.defiler() ;
    EXPECT_EQ(400, file_5.premier()) ;
    file_5.defiler() ;
    EXPECT_EQ(500, file_5.premier()) ;
    file_5.defiler() ;
    EXPECT_TRUE(file_5.estVide()) ;
    EXPECT_THROW(file_5.premier(), std::runtime_error) ;
    EXPECT_THROW(file_5.defiler(), std::runtime_error) ;
}

TEST_F(FileTest, enfiler_defiler_bonne_sequence) {
    file_5.defiler() ;
    file_5.defiler() ;
    file_5.defiler() ;
    file_5.enfiler(2) ;
    EXPECT_EQ(400, file_5.premier()) ;
    file_5.defiler() ;
    EXPECT_EQ(500, file_5.premier()) ;
    file_5.defiler() ;
    EXPECT_EQ(2, file_5.premier()) ;
    file_5.defiler() ;
    EXPECT_TRUE(file_5.estVide()) ;
}

TEST_F(FileTest, enfiler_defiler_wraparound) {
    file_2.enfiler(3) ;
    EXPECT_EQ(1, file_2.premier()) ;
    file_2.defiler() ;

    file_2.enfiler(4) ;
    EXPECT_EQ(2, file_2.premier()) ;
    file_2.defiler() ;

    file_2.enfiler(5) ;
    EXPECT_EQ(3, file_2.premier()) ;
    file_2.defiler() ;

    file_2.enfiler(6) ;
    EXPECT_EQ(4, file_2.premier()) ;
    file_2.defiler() ;

    file_2.enfiler(7) ;
    EXPECT_EQ(5, file_2.premier()) ;
    EXPECT_EQ(1, file_2.disponible()) ;
}

TEST_F(FileTest, vider_file_est_vide) {
    file_5.vider() ;
    EXPECT_TRUE(file_5.estVide()) ;
}

TEST_F(FileTest, agrandir_augmente_la_capacite_liste_vide) {
    file_vide.agrandir(2 * td4::File<int>::cap_defaut) ;
    EXPECT_EQ(2 * td4::File<int>::cap_defaut, file_vide.disponible()) ;
}

TEST_F(FileTest, agrandir_augmente_la_capacite_liste_5) {
    file_5.agrandir(15) ;
    EXPECT_EQ(10, file_5.disponible()) ;
}