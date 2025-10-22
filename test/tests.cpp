#include <gtest/gtest.h>
#include "../include/array.h"
#include "../include/figure.h"
#include "../include/triangle.h"
#include "../include/square.h"
#include "../include/eightug.h"

using namespace std;

constexpr double eps = 1e-6;

// === Triangle tests ===

TEST(test_t1, centr_coord) 
{
    Triangle t(0, 0, 3, 0, 0, 3);

    auto [centr_x, centr_y] = t.get_centr();
    EXPECT_NEAR(centr_x, 1, eps);
    EXPECT_NEAR(centr_y, 1, eps);

    double square = static_cast<double>(t);
    EXPECT_NEAR(square, 4.5, eps);
}

TEST(test_t2, zero_centr_coord) 
{
    Triangle t(0, 0, 0, 0, 0, 0);

    auto [centr_x, centr_y] = t.get_centr();
    EXPECT_NEAR(centr_x, 0, eps);
    EXPECT_NEAR(centr_y, 0, eps);

    double square = static_cast<double>(t);
    EXPECT_NEAR(square, 0, eps);
}

TEST(test_t3, double_centr_coord) 
{
    Triangle t(0.5, 1.5, 3, 4.5, 5.5, 1.5);

    auto [centr_x, centr_y] = t.get_centr();
    EXPECT_NEAR(centr_x, 3, eps);
    EXPECT_NEAR(centr_y, 2.5, eps);

    double square = static_cast<double>(t);
    EXPECT_NEAR(square, 7.5, eps);
}

// === Square tests ===

TEST(test_k1, centr_coord) 
{
    Square s(0, 0, 3, 0, 3, 3, 0, 3);

    auto [centr_x, centr_y] = s.get_centr();
    EXPECT_NEAR(centr_x, 1.5, eps);
    EXPECT_NEAR(centr_y, 1.5, eps);

    double square = static_cast<double>(s);
    EXPECT_NEAR(square, 9, eps);
}

TEST(test_k2, zero_centr_coord) 
{
    Square s(0, 0, 0, 0, 0, 0, 0, 0);

    auto [centr_x, centr_y] = s.get_centr();
    EXPECT_NEAR(centr_x, 0, eps);
    EXPECT_NEAR(centr_y, 0, eps);

    double square = static_cast<double>(s);
    EXPECT_NEAR(square, 0, eps);
}

TEST(test_k3, double_centr_coord) 
{
    Square s(1.5, 1.5, 4, 1.5, 4, 4, 1.5, 4);

    auto [centr_x, centr_y] = s.get_centr();
    EXPECT_NEAR(centr_x, 2.75, eps);
    EXPECT_NEAR(centr_y, 2.75, eps);

    double square = static_cast<double>(s);
    EXPECT_NEAR(square, 6.25, eps);
}

// === Eightugolnik tests ===

TEST(test_e1, centr_coord) 
{
    Eightug e(1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1, -2, 1, -1, 2);

    auto [centr_x, centr_y] = e.get_centr();
    EXPECT_NEAR(centr_x, 0, eps);
    EXPECT_NEAR(centr_y, 0, eps);

    double square = static_cast<double>(e);
    EXPECT_NEAR(square, 14, eps);
}

TEST(test_e2, zero_centr_coord) 
{
    Eightug e(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

    auto [centr_x, centr_y] = e.get_centr();
    EXPECT_NEAR(centr_x, 0, eps);
    EXPECT_NEAR(centr_y, 0, eps);

    double square = static_cast<double>(e);
    EXPECT_NEAR(square, 0, eps);
}

TEST(test_e3, double_centr_coord) 
{
    Eightug e(6.5, 7.5, 7.5, 6.5, 7.5, 4.5, 6.5, 3.5, 4.5, 3.5, 3.5, 4.5, 3.5, 6.5, 4.5, 7.5);

    auto [centr_x, centr_y] = e.get_centr();
    EXPECT_NEAR(centr_x, 5.5, eps);
    EXPECT_NEAR(centr_y, 5.5, eps);

    double square = static_cast<double>(e);
    EXPECT_NEAR(square, 14, eps);
}

// === Array funcs tests ===

class ArrayTest : public ::testing::Test {
protected:
    void SetUp() override {
        arr.add_to_arr(new Square(0, 0, 2, 0, 2, 2, 0, 2));
        arr.add_to_arr(new Triangle(0, 0, 3, 0, 0, 3));
    }

    Array arr;
};

TEST_F(ArrayTest, add_and_getSize) {
    ASSERT_EQ(arr.size(), 2);

    arr.add_to_arr(new Eightug(1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1, -2, 1, -1, 2));

    EXPECT_EQ(arr.size(), 3);
}

TEST_F(ArrayTest, total_square) {
    EXPECT_NEAR(arr.get_total_sqr(), 8.5, eps);
}

TEST_F(ArrayTest, delete_figure) {
    ASSERT_EQ(arr.size(), 2);
    arr.del_from_arr(1);
    
    ASSERT_EQ(arr.size(), 1);
    EXPECT_NEAR(arr.get_total_sqr(), 4.0, eps);
}

TEST_F(ArrayTest, empty_arr) {
    Array empty_arr;
    EXPECT_EQ(empty_arr.size(), 0);
    EXPECT_NEAR(empty_arr.get_total_sqr(), 0, eps);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
