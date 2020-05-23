#define SIMDE_TEST_ARM_NEON_INSN add

#include "test-neon.h"
#include "../../../simde/arm/neon/add.h"

static int
test_simde_vadd_f32 (void) {
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {

  };

  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x2_t
      a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f),
      b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f),
      r = simde_vadd_f32(a, b);
    
    simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x2_t
      a = simde_vld1_f32(test_vec[i].a),
      b = simde_vld1_f32(test_vec[i].b),
      r = simde_vadd_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x2(r, simde_vld1_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vadd_f64 (void) {
  struct {
    simde_float64 a[1];
    simde_float64 b[1];
    simde_float64 r[1];
  } test_vec[] = {

  };

  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x1_t
      a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0),
      b = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0),
      r = simde_vadd_f64(a, b);
    
    simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x1_t
      a = simde_vld1_f64(test_vec[i].a),
      b = simde_vld1_f64(test_vec[i].b),
      r = simde_vadd_f64(a, b);
    simde_test_arm_neon_assert_equal_f64x1(r, simde_vld1_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vadd_s8 (void) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {

  };

  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x8_t
      a = simde_test_arm_neon_random_i8x8(),
      b = simde_test_arm_neon_random_i8x8(),
      r = simde_vadd_s8(a, b);
    
    simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x8_t
      a = simde_vld1_s8(test_vec[i].a),
      b = simde_vld1_s8(test_vec[i].b),
      r = simde_vadd_s8(a, b);
    simde_test_arm_neon_assert_equal_i8x8(r, simde_vld1_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vadd_s16 (void) {
  struct {
    int16_t a[4];
    int16_t b[4];
    int16_t r[4];
  } test_vec[] = {

  };

  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x4_t
      a = simde_test_arm_neon_random_i16x4(),
      b = simde_test_arm_neon_random_i16x4(),
      r = simde_vadd_s16(a, b);
    
    simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x4_t
      a = simde_vld1_s16(test_vec[i].a),
      b = simde_vld1_s16(test_vec[i].b),
      r = simde_vadd_s16(a, b);
    simde_test_arm_neon_assert_equal_i16x4(r, simde_vld1_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vadd_s32 (void) {
  struct {
    int32_t a[2];
    int32_t b[2];
    int32_t r[2];
  } test_vec[] = {

  };

  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x2_t
      a = simde_test_arm_neon_random_i32x2(),
      b = simde_test_arm_neon_random_i32x2(),
      r = simde_vadd_s32(a, b);
    
    simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x2_t
      a = simde_vld1_s32(test_vec[i].a),
      b = simde_vld1_s32(test_vec[i].b),
      r = simde_vadd_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x2(r, simde_vld1_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vadd_s64 (void) {
  struct {
    int64_t a[1];
    int64_t b[1];
    int64_t r[1];
  } test_vec[] = {

  };

  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x1_t
      a = simde_test_arm_neon_random_i64x1(),
      b = simde_test_arm_neon_random_i64x1(),
      r = simde_vadd_s64(a, b);
    
    simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x1_t
      a = simde_vld1_s64(test_vec[i].a),
      b = simde_vld1_s64(test_vec[i].b),
      r = simde_vadd_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x1(r, simde_vld1_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddq_f32 (void) {
  struct {
    simde_float32 a[4];
    simde_float32 b[4];
    simde_float32 r[4];
  } test_vec[] = {

  };

  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float32x4_t
      a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f),
      b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f),
      r = simde_vaddq_f32(a, b);
    
    simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float32x4_t
      a = simde_vld1q_f32(test_vec[i].a),
      b = simde_vld1q_f32(test_vec[i].b),
      r = simde_vaddq_f32(a, b);
    simde_test_arm_neon_assert_equal_f32x4(r, simde_vld1q_f32(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vaddq_f64 (void) {
  struct {
    simde_float64 a[2];
    simde_float64 b[2];
    simde_float64 r[2];
  } test_vec[] = {

  };

  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_float64x2_t
      a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0),
      b = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0),
      r = simde_vaddq_f64(a, b);
    
    simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_float64x2_t
      a = simde_vld1q_f64(test_vec[i].a),
      b = simde_vld1q_f64(test_vec[i].b),
      r = simde_vaddq_f64(a, b);
    simde_test_arm_neon_assert_equal_f64x2(r, simde_vld1q_f64(test_vec[i].r), 1);
  }

  return 0;
}

static int
test_simde_vaddq_s8 (void) {
  struct {
    int8_t a[16];
    int8_t b[16];
    int8_t r[16];
  } test_vec[] = {

  };

  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int8x16_t
      a = simde_test_arm_neon_random_i8x16(),
      b = simde_test_arm_neon_random_i8x16(),
      r = simde_vaddq_s8(a, b);
    
    simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int8x16_t
      a = simde_vld1q_s8(test_vec[i].a),
      b = simde_vld1q_s8(test_vec[i].b),
      r = simde_vaddq_s8(a, b);
    simde_test_arm_neon_assert_equal_i8x16(r, simde_vld1q_s8(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddq_s16 (void) {
  struct {
    int16_t a[8];
    int16_t b[8];
    int16_t r[8];
  } test_vec[] = {

  };

  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int16x8_t
      a = simde_test_arm_neon_random_i16x8(),
      b = simde_test_arm_neon_random_i16x8(),
      r = simde_vaddq_s16(a, b);
    
    simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int16x8_t
      a = simde_vld1q_s16(test_vec[i].a),
      b = simde_vld1q_s16(test_vec[i].b),
      r = simde_vaddq_s16(a, b);
    simde_test_arm_neon_assert_equal_i16x8(r, simde_vld1q_s16(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddq_s32 (void) {
  struct {
    int32_t a[4];
    int32_t b[4];
    int32_t r[4];
  } test_vec[] = {

  };

  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int32x4_t
      a = simde_test_arm_neon_random_i32x4(),
      b = simde_test_arm_neon_random_i32x4(),
      r = simde_vaddq_s32(a, b);
    
    simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int32x4_t
      a = simde_vld1q_s32(test_vec[i].a),
      b = simde_vld1q_s32(test_vec[i].b),
      r = simde_vaddq_s32(a, b);
    simde_test_arm_neon_assert_equal_i32x4(r, simde_vld1q_s32(test_vec[i].r));
  }

  return 0;
}

static int
test_simde_vaddq_s64 (void) {
  struct {
    int64_t a[2];
    int64_t b[2];
    int64_t r[2];
  } test_vec[] = {

  };

  fputc('\n', stdout);
  for (int i = 0 ; i < 8 ; i++) {
    simde_int64x2_t
      a = simde_test_arm_neon_random_i64x2(),
      b = simde_test_arm_neon_random_i64x2(),
      r = simde_vaddq_s64(a, b);
    
    simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
    simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
    simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  }
  return 1;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t
      a = simde_vld1q_s64(test_vec[i].a),
      b = simde_vld1q_s64(test_vec[i].b),
      r = simde_vaddq_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

  return 0;
}

static int
test_arm_neon_vaddq_s16 (void) {
  return 0;
}

SIMDE_TEST_FUNC_LIST_BEGIN
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vadd_s64)

SIMDE_TEST_FUNC_LIST_ENTRY(vaddq_f32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddq_f64)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddq_s8)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddq_s16)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddq_s32)
SIMDE_TEST_FUNC_LIST_ENTRY(vaddq_s64)
SIMDE_TEST_FUNC_LIST_END

#include "test-neon-footer.h"
