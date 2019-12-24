//
// Created by ser on 17.12.2019.
//

#include <gtest/gtest.h>

extern "C" {
    #include "utils.h"
}

TEST(UtilsTest, VectorPushBackTest) {
    Vector *v = create();
    for (int i = 0; i < 1000; ++i) {
        push_back(v, i);
    }
    ASSERT_EQ(1000, v->size);
    ASSERT_EQ(1024, v->capacity);
    for (int i = 0; i < 1000; ++i) {
        ASSERT_EQ(get_at(v, i), i);
    }
    delete_vec(v);
}

TEST(UtilsTest, VectorSetAndGetTest) {
    Vector *v = create_size(1000);
    for (int i = 0; i < 1000; ++i) {
        set_at(v, i, i);
    }
    for (int i = 0; i < 1000; ++i) {
        ASSERT_EQ(get_at(v, i), i);
    }
    ASSERT_EQ(1000, v->size);
    ASSERT_EQ(1000, v->capacity);
    delete_vec(v);
}

TEST(UtilsTest, VectorCreateFromArrayTest) {
    unsigned int arr[100];
    for (int i = 0; i < 100; ++i) {
        arr[i] = i;
    }
    Vector *v = create_from(100, arr);
    ASSERT_EQ(v->size, 100);
    ASSERT_EQ(v->capacity, 100);
    for (int j = 0; j < 100; ++j) {
        ASSERT_EQ(get_at(v, j), j);
    }
    delete_vec(v);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
