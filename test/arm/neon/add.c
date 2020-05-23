#define SIMDE_TEST_ARM_NEON_INSN add

#include <test/arm/neon/test-neon.h>
#include <simde/arm/neon/add.h>

static int
test_simde_vadd_f32 (void) {
  struct {
    simde_float32 a[2];
    simde_float32 b[2];
    simde_float32 r[2];
  } test_vec[] = {
    { { SIMDE_FLOAT32_C(  -391.63), SIMDE_FLOAT32_C(   170.95) },
      { SIMDE_FLOAT32_C(   608.04), SIMDE_FLOAT32_C(  -754.94) },
      { SIMDE_FLOAT32_C(   216.41), SIMDE_FLOAT32_C(  -583.99) } },
    { { SIMDE_FLOAT32_C(  -601.58), SIMDE_FLOAT32_C(   647.19) },
      { SIMDE_FLOAT32_C(   810.45), SIMDE_FLOAT32_C(  -196.34) },
      { SIMDE_FLOAT32_C(   208.86), SIMDE_FLOAT32_C(   450.85) } },
    { { SIMDE_FLOAT32_C(    46.89), SIMDE_FLOAT32_C(    -6.39) },
      { SIMDE_FLOAT32_C(   509.79), SIMDE_FLOAT32_C(   965.96) },
      { SIMDE_FLOAT32_C(   556.67), SIMDE_FLOAT32_C(   959.57) } },
    { { SIMDE_FLOAT32_C(  -995.08), SIMDE_FLOAT32_C(  -351.35) },
      { SIMDE_FLOAT32_C(   973.13), SIMDE_FLOAT32_C(   465.92) },
      { SIMDE_FLOAT32_C(   -21.94), SIMDE_FLOAT32_C(   114.57) } },
    { { SIMDE_FLOAT32_C(   364.80), SIMDE_FLOAT32_C(   300.59) },
      { SIMDE_FLOAT32_C(  -383.35), SIMDE_FLOAT32_C(  -630.11) },
      { SIMDE_FLOAT32_C(   -18.55), SIMDE_FLOAT32_C(  -329.52) } },
    { { SIMDE_FLOAT32_C(   244.36), SIMDE_FLOAT32_C(  -743.18) },
      { SIMDE_FLOAT32_C(   -12.37), SIMDE_FLOAT32_C(   382.55) },
      { SIMDE_FLOAT32_C(   231.99), SIMDE_FLOAT32_C(  -360.62) } },
    { { SIMDE_FLOAT32_C(   -82.99), SIMDE_FLOAT32_C(   826.36) },
      { SIMDE_FLOAT32_C(   808.40), SIMDE_FLOAT32_C(  -612.89) },
      { SIMDE_FLOAT32_C(   725.41), SIMDE_FLOAT32_C(   213.47) } },
    { { SIMDE_FLOAT32_C(  -934.87), SIMDE_FLOAT32_C(    39.81) },
      { SIMDE_FLOAT32_C(  -755.99), SIMDE_FLOAT32_C(  -326.50) },
      { SIMDE_FLOAT32_C( -1690.85), SIMDE_FLOAT32_C(  -286.68) } }
  };

  // fputc('\n', stdout);
  // for (int i = 0 ; i < 8 ; i++) {
  //   simde_float32x2_t
  //     a = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f),
  //     b = simde_test_arm_neon_random_f32x2(-1000.0f, 1000.0f),
  //     r = simde_vadd_f32(a, b);
    
  //   simde_test_arm_neon_write_f32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
  //   simde_test_arm_neon_write_f32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  //   simde_test_arm_neon_write_f32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  // }
  // return 1;

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
    { { SIMDE_FLOAT64_C(   -24.41) },
      { SIMDE_FLOAT64_C(    23.57) },
      { SIMDE_FLOAT64_C(    -0.84) } },
    { { SIMDE_FLOAT64_C(  -594.99) },
      { SIMDE_FLOAT64_C(  -529.75) },
      { SIMDE_FLOAT64_C( -1124.75) } },
    { { SIMDE_FLOAT64_C(   -34.79) },
      { SIMDE_FLOAT64_C(  -269.13) },
      { SIMDE_FLOAT64_C(  -303.92) } },
    { { SIMDE_FLOAT64_C(  -613.97) },
      { SIMDE_FLOAT64_C(   967.32) },
      { SIMDE_FLOAT64_C(   353.35) } },
    { { SIMDE_FLOAT64_C(  -930.88) },
      { SIMDE_FLOAT64_C(   -96.48) },
      { SIMDE_FLOAT64_C( -1027.35) } },
    { { SIMDE_FLOAT64_C(   252.21) },
      { SIMDE_FLOAT64_C(   208.57) },
      { SIMDE_FLOAT64_C(   460.79) } },
    { { SIMDE_FLOAT64_C(   873.32) },
      { SIMDE_FLOAT64_C(   853.78) },
      { SIMDE_FLOAT64_C(  1727.10) } },
    { { SIMDE_FLOAT64_C(   245.86) },
      { SIMDE_FLOAT64_C(   110.36) },
      { SIMDE_FLOAT64_C(   356.22) } }
  };

  // fputc('\n', stdout);
  // for (int i = 0 ; i < 8 ; i++) {
  //   simde_float64x1_t
  //     a = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0),
  //     b = simde_test_arm_neon_random_f64x1(-1000.0, 1000.0),
  //     r = simde_vadd_f64(a, b);
    
  //   simde_test_arm_neon_write_f64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
  //   simde_test_arm_neon_write_f64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  //   simde_test_arm_neon_write_f64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  // }
  // return 1;

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
    { { -INT8_C(122),  INT8_C( 87), -INT8_C( 95),  INT8_C( 95),  INT8_C( 87), -INT8_C(115),  INT8_C( 60),  INT8_C(  3) },
      {  INT8_C(114),  INT8_C(  1), -INT8_C(119),  INT8_C( 20), -INT8_C( 25), -INT8_C( 90),  INT8_C( 28),  INT8_C( 65) },
      { -INT8_C(  8),  INT8_C( 88),  INT8_C( 42),  INT8_C(115),  INT8_C( 62),  INT8_C( 51),  INT8_C( 88),  INT8_C( 68) } },
    { { -INT8_C( 51), -INT8_C(  9),  INT8_C( 82),  INT8_C(119),  INT8_C( 51),  INT8_C(112),  INT8_C(  5),  INT8_C( 38) },
      { -INT8_C( 67),  INT8_C(  6),  INT8_C(  3), -INT8_C(121),  INT8_C( 29), -INT8_C(  4),  INT8_C( 34), -INT8_C( 93) },
      { -INT8_C(118), -INT8_C(  3),  INT8_C( 85), -INT8_C(  2),  INT8_C( 80),  INT8_C(108),  INT8_C( 39), -INT8_C( 55) } },
    { {  INT8_C( 83), -INT8_C( 60),  INT8_C(  2), -INT8_C( 86),  INT8_C( 81),  INT8_C( 62), -INT8_C( 83), -INT8_C( 60) },
      {  INT8_C( 63),  INT8_C( 54), -INT8_C( 40),  INT8_C( 38), -INT8_C( 36), -INT8_C( 11),  INT8_C(103), -INT8_C( 86) },
      { -INT8_C(110), -INT8_C(  6), -INT8_C( 38), -INT8_C( 48),  INT8_C( 45),  INT8_C( 51),  INT8_C( 20),  INT8_C(110) } },
    { { -INT8_C( 20), -INT8_C( 71),  INT8_C( 33),  INT8_C( 32),  INT8_C( 41),  INT8_C( 38),  INT8_C( 70), -INT8_C( 25) },
      {  INT8_C( 44),  INT8_C( 74),  INT8_C(110),  INT8_C( 73),  INT8_C( 70), -INT8_C(111), -INT8_C( 20), -INT8_C(103) },
      {  INT8_C( 24),  INT8_C(  3), -INT8_C(113),  INT8_C(105),  INT8_C(111), -INT8_C( 73),  INT8_C( 50),     INT8_MIN } },
    { {  INT8_C( 85), -INT8_C( 18),  INT8_C( 67), -INT8_C( 90),  INT8_C( 44), -INT8_C( 16),  INT8_C(106),  INT8_C(108) },
      {  INT8_C( 39),  INT8_C( 67), -INT8_C(110),  INT8_C(  3),  INT8_C( 56), -INT8_C(  6), -INT8_C( 83),  INT8_C( 36) },
      {  INT8_C(124),  INT8_C( 49), -INT8_C( 43), -INT8_C( 87),  INT8_C(100), -INT8_C( 22),  INT8_C( 23), -INT8_C(112) } },
    { { -INT8_C( 77), -INT8_C( 50),  INT8_C( 68), -INT8_C( 35), -INT8_C( 12), -INT8_C(117), -INT8_C( 60),  INT8_C( 33) },
      { -INT8_C( 43),  INT8_C( 50),  INT8_C(106),  INT8_C( 27), -INT8_C( 61),  INT8_C( 87), -INT8_C( 76),  INT8_C( 24) },
      { -INT8_C(120),  INT8_C(  0), -INT8_C( 82), -INT8_C(  8), -INT8_C( 73), -INT8_C( 30),  INT8_C(120),  INT8_C( 57) } },
    { {  INT8_C( 69), -INT8_C(  9), -INT8_C( 65),  INT8_C(114), -INT8_C( 25),  INT8_C( 41), -INT8_C( 34),  INT8_C( 14) },
      {  INT8_C(108),  INT8_C(112),  INT8_C( 18), -INT8_C( 92),  INT8_C(106), -INT8_C( 65), -INT8_C( 55),  INT8_C( 30) },
      { -INT8_C( 79),  INT8_C(103), -INT8_C( 47),  INT8_C( 22),  INT8_C( 81), -INT8_C( 24), -INT8_C( 89),  INT8_C( 44) } },
    { { -INT8_C(114),  INT8_C( 13), -INT8_C(  5), -INT8_C(126), -INT8_C(104), -INT8_C( 65), -INT8_C( 93),  INT8_C(109) },
      { -INT8_C( 15),  INT8_C( 14), -INT8_C(120), -INT8_C( 75),  INT8_C(101),  INT8_C( 60), -INT8_C( 51), -INT8_C( 86) },
      {     INT8_MAX,  INT8_C( 27), -INT8_C(125),  INT8_C( 55), -INT8_C(  3), -INT8_C(  5),  INT8_C(112),  INT8_C( 23) } }
  };

  // fputc('\n', stdout);
  // for (int i = 0 ; i < 8 ; i++) {
  //   simde_int8x8_t
  //     a = simde_test_arm_neon_random_i8x8(),
  //     b = simde_test_arm_neon_random_i8x8(),
  //     r = simde_vadd_s8(a, b);
    
  //   simde_test_arm_neon_write_i8x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  //   simde_test_arm_neon_write_i8x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  //   simde_test_arm_neon_write_i8x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  // }
  // return 1;

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
    { { -INT16_C(  947), -INT16_C(22973),  INT16_C( 4616), -INT16_C(18914) },
      { -INT16_C(26826), -INT16_C(11870),  INT16_C( 8936), -INT16_C( 8502) },
      { -INT16_C(27773),  INT16_C(30693),  INT16_C(13552), -INT16_C(27416) } },
    { {  INT16_C(29630), -INT16_C( 3455), -INT16_C( 3281),  INT16_C(13442) },
      {  INT16_C( 6170), -INT16_C(27389), -INT16_C(18713),  INT16_C(13604) },
      { -INT16_C(29736), -INT16_C(30844), -INT16_C(21994),  INT16_C(27046) } },
    { {  INT16_C(26802), -INT16_C(17701), -INT16_C( 1414), -INT16_C(20367) },
      {  INT16_C( 5009),  INT16_C(31105),  INT16_C(19509), -INT16_C( 3241) },
      {  INT16_C(31811),  INT16_C(13404),  INT16_C(18095), -INT16_C(23608) } },
    { { -INT16_C( 9793), -INT16_C( 4123),  INT16_C(26828), -INT16_C( 6365) },
      {  INT16_C( 9856),  INT16_C(26748), -INT16_C(24099), -INT16_C(28771) },
      {  INT16_C(   63),  INT16_C(22625),  INT16_C( 2729),  INT16_C(30400) } },
    { {  INT16_C(30729), -INT16_C(31926), -INT16_C(17550),  INT16_C( 1076) },
      { -INT16_C(18994),  INT16_C(  893), -INT16_C(11007), -INT16_C(15881) },
      {  INT16_C(11735), -INT16_C(31033), -INT16_C(28557), -INT16_C(14805) } },
    { { -INT16_C( 9042),  INT16_C(31408), -INT16_C(11452), -INT16_C(15007) },
      { -INT16_C( 8455), -INT16_C(10707), -INT16_C(13697), -INT16_C(30618) },
      { -INT16_C(17497),  INT16_C(20701), -INT16_C(25149),  INT16_C(19911) } },
    { { -INT16_C(20414), -INT16_C(19189),  INT16_C(16235),  INT16_C(14777) },
      {  INT16_C(14069), -INT16_C( 2500),  INT16_C(13067), -INT16_C(17993) },
      { -INT16_C( 6345), -INT16_C(21689),  INT16_C(29302), -INT16_C( 3216) } },
    { {  INT16_C(26384),  INT16_C(21556), -INT16_C(27334),  INT16_C(13337) },
      {  INT16_C(18035), -INT16_C( 3574),  INT16_C(28688),  INT16_C(21370) },
      { -INT16_C(21117),  INT16_C(17982),  INT16_C( 1354), -INT16_C(30829) } }
  };

  // fputc('\n', stdout);
  // for (int i = 0 ; i < 8 ; i++) {
  //   simde_int16x4_t
  //     a = simde_test_arm_neon_random_i16x4(),
  //     b = simde_test_arm_neon_random_i16x4(),
  //     r = simde_vadd_s16(a, b);
    
  //   simde_test_arm_neon_write_i16x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  //   simde_test_arm_neon_write_i16x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  //   simde_test_arm_neon_write_i16x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  // }
  // return 1;

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
    { {  INT32_C( 215015982), -INT32_C(1865408597) },
      {  INT32_C(1846622177),  INT32_C(1595050320) },
      {  INT32_C(2061638159), -INT32_C( 270358277) } },
    { {  INT32_C( 810299768), -INT32_C(1379972612) },
      {  INT32_C(1110843670), -INT32_C(2147252143) },
      {  INT32_C(1921143438),  INT32_C( 767742541) } },
    { {  INT32_C( 378328170), -INT32_C( 710517261) },
      { -INT32_C( 448546924), -INT32_C(1203481280) },
      { -INT32_C(  70218754), -INT32_C(1913998541) } },
    { { -INT32_C(2098687866), -INT32_C( 265312038) },
      {  INT32_C( 456287689),  INT32_C(1486567149) },
      { -INT32_C(1642400177),  INT32_C(1221255111) } },
    { { -INT32_C(  43112694),  INT32_C( 433198212) },
      {  INT32_C( 201201099), -INT32_C( 238861717) },
      {  INT32_C( 158088405),  INT32_C( 194336495) } },
    { { -INT32_C(1384862765),  INT32_C( 496870227) },
      { -INT32_C( 164049143),  INT32_C( 256824069) },
      { -INT32_C(1548911908),  INT32_C( 753694296) } },
    { {  INT32_C(2131606778), -INT32_C(1684480048) },
      {  INT32_C(1621530357), -INT32_C(1420727848) },
      { -INT32_C( 541830161),  INT32_C(1189759400) } },
    { {  INT32_C(1750648085),  INT32_C(1921381737) },
      { -INT32_C( 899105339), -INT32_C(1948600432) },
      {  INT32_C( 851542746), -INT32_C(  27218695) } }
  };

  // fputc('\n', stdout);
  // for (int i = 0 ; i < 8 ; i++) {
  //   simde_int32x2_t
  //     a = simde_test_arm_neon_random_i32x2(),
  //     b = simde_test_arm_neon_random_i32x2(),
  //     r = simde_vadd_s32(a, b);
    
  //   simde_test_arm_neon_write_i32x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
  //   simde_test_arm_neon_write_i32x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  //   simde_test_arm_neon_write_i32x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  // }
  // return 1;

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
    { { -INT64_C(6953418867158845111) },
      { -INT64_C(1779476666663516076) },
      { -INT64_C(8732895533822361187) } },
    { { -INT64_C(1126018337766800454) },
      {  INT64_C(2258022871352771297) },
      {  INT64_C(1132004533585970843) } },
    { { -INT64_C(6227299243289225580) },
      { -INT64_C(4519841581477527304) },
      {  INT64_C(7699603248942798732) } },
    { { -INT64_C(8067980277103256625) },
      {  INT64_C(7439502188966426696) },
      { -INT64_C( 628478088136829929) } },
    { {  INT64_C(1603265106041237057) },
      {  INT64_C(6465967895585570290) },
      {  INT64_C(8069233001626807347) } },
    { {  INT64_C(3536868225754211030) },
      { -INT64_C(2923241237898057165) },
      {  INT64_C( 613626987856153865) } },
    { { -INT64_C(5858711714170811523) },
      { -INT64_C(5202392174583863575) },
      {  INT64_C(7385640184954876518) } },
    { { -INT64_C(1396026027624611963) },
      { -INT64_C( 222820983164899205) },
      { -INT64_C(1618847010789511168) } }
  };

  // fputc('\n', stdout);
  // for (int i = 0 ; i < 8 ; i++) {
  //   simde_int64x1_t
  //     a = simde_test_arm_neon_random_i64x1(),
  //     b = simde_test_arm_neon_random_i64x1(),
  //     r = simde_vadd_s64(a, b);
    
  //   simde_test_arm_neon_write_i64x1(2, a, SIMDE_TEST_VEC_POS_FIRST);
  //   simde_test_arm_neon_write_i64x1(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  //   simde_test_arm_neon_write_i64x1(2, r, SIMDE_TEST_VEC_POS_LAST);
  // }
  // return 1;

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
    { { SIMDE_FLOAT32_C(  -431.52), SIMDE_FLOAT32_C(    11.00), SIMDE_FLOAT32_C(   872.75), SIMDE_FLOAT32_C(   198.45) },
      { SIMDE_FLOAT32_C(  -336.41), SIMDE_FLOAT32_C(   760.17), SIMDE_FLOAT32_C(   837.28), SIMDE_FLOAT32_C(    86.87) },
      { SIMDE_FLOAT32_C(  -767.93), SIMDE_FLOAT32_C(   771.17), SIMDE_FLOAT32_C(  1710.03), SIMDE_FLOAT32_C(   285.32) } },
    { { SIMDE_FLOAT32_C(  -460.28), SIMDE_FLOAT32_C(  -637.80), SIMDE_FLOAT32_C(   915.06), SIMDE_FLOAT32_C(   882.58) },
      { SIMDE_FLOAT32_C(  -381.76), SIMDE_FLOAT32_C(  -777.02), SIMDE_FLOAT32_C(  -617.81), SIMDE_FLOAT32_C(  -190.72) },
      { SIMDE_FLOAT32_C(  -842.04), SIMDE_FLOAT32_C( -1414.82), SIMDE_FLOAT32_C(   297.25), SIMDE_FLOAT32_C(   691.86) } },
    { { SIMDE_FLOAT32_C(   734.58), SIMDE_FLOAT32_C(   478.38), SIMDE_FLOAT32_C(  -876.48), SIMDE_FLOAT32_C(   254.24) },
      { SIMDE_FLOAT32_C(   968.28), SIMDE_FLOAT32_C(   827.65), SIMDE_FLOAT32_C(     9.82), SIMDE_FLOAT32_C(  -667.33) },
      { SIMDE_FLOAT32_C(  1702.86), SIMDE_FLOAT32_C(  1306.04), SIMDE_FLOAT32_C(  -866.66), SIMDE_FLOAT32_C(  -413.09) } },
    { { SIMDE_FLOAT32_C(  -998.01), SIMDE_FLOAT32_C(   632.61), SIMDE_FLOAT32_C(  -746.47), SIMDE_FLOAT32_C(  -237.58) },
      { SIMDE_FLOAT32_C(  -351.04), SIMDE_FLOAT32_C(  -927.63), SIMDE_FLOAT32_C(   322.49), SIMDE_FLOAT32_C(   217.44) },
      { SIMDE_FLOAT32_C( -1349.05), SIMDE_FLOAT32_C(  -295.02), SIMDE_FLOAT32_C(  -423.98), SIMDE_FLOAT32_C(   -20.14) } },
    { { SIMDE_FLOAT32_C(    83.37), SIMDE_FLOAT32_C(   195.24), SIMDE_FLOAT32_C(  -584.11), SIMDE_FLOAT32_C(   746.97) },
      { SIMDE_FLOAT32_C(   -44.59), SIMDE_FLOAT32_C(  -746.83), SIMDE_FLOAT32_C(  -166.16), SIMDE_FLOAT32_C(   495.13) },
      { SIMDE_FLOAT32_C(    38.78), SIMDE_FLOAT32_C(  -551.59), SIMDE_FLOAT32_C(  -750.27), SIMDE_FLOAT32_C(  1242.09) } },
    { { SIMDE_FLOAT32_C(  -384.63), SIMDE_FLOAT32_C(  -251.11), SIMDE_FLOAT32_C(   377.71), SIMDE_FLOAT32_C(   233.61) },
      { SIMDE_FLOAT32_C(   -28.13), SIMDE_FLOAT32_C(   759.90), SIMDE_FLOAT32_C(  -957.11), SIMDE_FLOAT32_C(  -293.55) },
      { SIMDE_FLOAT32_C(  -412.76), SIMDE_FLOAT32_C(   508.79), SIMDE_FLOAT32_C(  -579.40), SIMDE_FLOAT32_C(   -59.94) } },
    { { SIMDE_FLOAT32_C(   238.28), SIMDE_FLOAT32_C(  -833.58), SIMDE_FLOAT32_C(   960.69), SIMDE_FLOAT32_C(   206.56) },
      { SIMDE_FLOAT32_C(   994.07), SIMDE_FLOAT32_C(   -29.49), SIMDE_FLOAT32_C(   539.23), SIMDE_FLOAT32_C(   996.07) },
      { SIMDE_FLOAT32_C(  1232.35), SIMDE_FLOAT32_C(  -863.08), SIMDE_FLOAT32_C(  1499.92), SIMDE_FLOAT32_C(  1202.62) } },
    { { SIMDE_FLOAT32_C(  -396.89), SIMDE_FLOAT32_C(   792.76), SIMDE_FLOAT32_C(  -241.51), SIMDE_FLOAT32_C(   252.07) },
      { SIMDE_FLOAT32_C(   865.13), SIMDE_FLOAT32_C(  -919.03), SIMDE_FLOAT32_C(  -530.49), SIMDE_FLOAT32_C(   -51.49) },
      { SIMDE_FLOAT32_C(   468.24), SIMDE_FLOAT32_C(  -126.27), SIMDE_FLOAT32_C(  -772.00), SIMDE_FLOAT32_C(   200.58) } }
  };

  // fputc('\n', stdout);
  // for (int i = 0 ; i < 8 ; i++) {
  //   simde_float32x4_t
  //     a = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f),
  //     b = simde_test_arm_neon_random_f32x4(-1000.0f, 1000.0f),
  //     r = simde_vaddq_f32(a, b);
    
  //   simde_test_arm_neon_write_f32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  //   simde_test_arm_neon_write_f32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  //   simde_test_arm_neon_write_f32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  // }
  // return 1;

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
    { { SIMDE_FLOAT64_C(  -431.52), SIMDE_FLOAT64_C(    11.00) },
      { SIMDE_FLOAT64_C(   872.75), SIMDE_FLOAT64_C(   198.45) },
      { SIMDE_FLOAT64_C(   441.23), SIMDE_FLOAT64_C(   209.45) } },
    { { SIMDE_FLOAT64_C(  -336.41), SIMDE_FLOAT64_C(   760.17) },
      { SIMDE_FLOAT64_C(   837.28), SIMDE_FLOAT64_C(    86.87) },
      { SIMDE_FLOAT64_C(   500.87), SIMDE_FLOAT64_C(   847.04) } },
    { { SIMDE_FLOAT64_C(  -460.28), SIMDE_FLOAT64_C(  -637.80) },
      { SIMDE_FLOAT64_C(   915.06), SIMDE_FLOAT64_C(   882.58) },
      { SIMDE_FLOAT64_C(   454.78), SIMDE_FLOAT64_C(   244.78) } },
    { { SIMDE_FLOAT64_C(  -381.76), SIMDE_FLOAT64_C(  -777.02) },
      { SIMDE_FLOAT64_C(  -617.81), SIMDE_FLOAT64_C(  -190.72) },
      { SIMDE_FLOAT64_C(  -999.57), SIMDE_FLOAT64_C(  -967.74) } },
    { { SIMDE_FLOAT64_C(   734.58), SIMDE_FLOAT64_C(   478.38) },
      { SIMDE_FLOAT64_C(  -876.48), SIMDE_FLOAT64_C(   254.24) },
      { SIMDE_FLOAT64_C(  -141.89), SIMDE_FLOAT64_C(   732.62) } },
    { { SIMDE_FLOAT64_C(   968.28), SIMDE_FLOAT64_C(   827.65) },
      { SIMDE_FLOAT64_C(     9.82), SIMDE_FLOAT64_C(  -667.33) },
      { SIMDE_FLOAT64_C(   978.10), SIMDE_FLOAT64_C(   160.33) } },
    { { SIMDE_FLOAT64_C(  -998.01), SIMDE_FLOAT64_C(   632.61) },
      { SIMDE_FLOAT64_C(  -746.47), SIMDE_FLOAT64_C(  -237.58) },
      { SIMDE_FLOAT64_C( -1744.48), SIMDE_FLOAT64_C(   395.03) } },
    { { SIMDE_FLOAT64_C(  -351.04), SIMDE_FLOAT64_C(  -927.63) },
      { SIMDE_FLOAT64_C(   322.49), SIMDE_FLOAT64_C(   217.44) },
      { SIMDE_FLOAT64_C(   -28.55), SIMDE_FLOAT64_C(  -710.19) } }
  };

  // fputc('\n', stdout);
  // for (int i = 0 ; i < 8 ; i++) {
  //   simde_float64x2_t
  //     a = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0),
  //     b = simde_test_arm_neon_random_f64x2(-1000.0, 1000.0),
  //     r = simde_vaddq_f64(a, b);
    
  //   simde_test_arm_neon_write_f64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
  //   simde_test_arm_neon_write_f64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  //   simde_test_arm_neon_write_f64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  // }
  // return 1;

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
    { { -INT8_C(100), -INT8_C( 92), -INT8_C(  9), -INT8_C( 67),  INT8_C( 13), -INT8_C( 57), -INT8_C( 64),  INT8_C( 11),
        -INT8_C( 12), -INT8_C( 49),  INT8_C( 20),  INT8_C( 96),  INT8_C(108), -INT8_C( 82),  INT8_C( 89),  INT8_C(114) },
      { -INT8_C( 25),  INT8_C( 15), -INT8_C( 53), -INT8_C( 80), -INT8_C( 71), -INT8_C( 84),  INT8_C( 42),  INT8_C( 99),
        -INT8_C( 19), -INT8_C( 18),  INT8_C( 21), -INT8_C( 45), -INT8_C(114),  INT8_C( 55),  INT8_C( 75),  INT8_C( 43) },
      { -INT8_C(125), -INT8_C( 77), -INT8_C( 62),  INT8_C(109), -INT8_C( 58),  INT8_C(115), -INT8_C( 22),  INT8_C(110),
        -INT8_C( 31), -INT8_C( 67),  INT8_C( 41),  INT8_C( 51), -INT8_C(  6), -INT8_C( 27), -INT8_C( 92), -INT8_C( 99) } },
    { { -INT8_C( 36),  INT8_C( 66), -INT8_C( 24), -INT8_C( 23),  INT8_C(  9), -INT8_C( 88), -INT8_C( 12), -INT8_C(  3),
         INT8_C(119),  INT8_C(  8),  INT8_C( 93), -INT8_C( 29), -INT8_C( 74), -INT8_C( 74),  INT8_C( 86), -INT8_C( 98) },
      { -INT8_C( 58),  INT8_C( 33),  INT8_C( 78),     INT8_MAX, -INT8_C( 51),  INT8_C(120), -INT8_C( 30), -INT8_C( 70),
         INT8_C(103), -INT8_C(  8), -INT8_C(115), -INT8_C( 11),  INT8_C( 47), -INT8_C( 40),  INT8_C( 32),  INT8_C( 11) },
      { -INT8_C( 94),  INT8_C( 99),  INT8_C( 54),  INT8_C(104), -INT8_C( 42),  INT8_C( 32), -INT8_C( 42), -INT8_C( 73),
        -INT8_C( 34),  INT8_C(  0), -INT8_C( 22), -INT8_C( 40), -INT8_C( 27), -INT8_C(114),  INT8_C(118), -INT8_C( 87) } },
    { {  INT8_C( 26),  INT8_C(  9), -INT8_C( 11),  INT8_C( 36), -INT8_C( 79), -INT8_C( 23),  INT8_C( 33),  INT8_C( 41),
        -INT8_C( 14),     INT8_MAX,  INT8_C( 12), -INT8_C( 88),  INT8_C( 53),  INT8_C( 98),  INT8_C( 70), -INT8_C(  5) },
      { -INT8_C(125), -INT8_C(108),  INT8_C(122),  INT8_C( 80),  INT8_C( 13),  INT8_C( 93),  INT8_C( 10),  INT8_C(116),
         INT8_C( 85), -INT8_C(105),  INT8_C(105), -INT8_C(124),  INT8_C(111), -INT8_C(118), -INT8_C(112), -INT8_C(118) },
      { -INT8_C( 99), -INT8_C( 99),  INT8_C(111),  INT8_C(116), -INT8_C( 66),  INT8_C( 70),  INT8_C( 43), -INT8_C( 99),
         INT8_C( 71),  INT8_C( 22),  INT8_C(117),  INT8_C( 44), -INT8_C( 92), -INT8_C( 20), -INT8_C( 42), -INT8_C(123) } },
    { { -INT8_C(109), -INT8_C(123), -INT8_C( 82),  INT8_C( 68),  INT8_C(110), -INT8_C( 49),  INT8_C(109),  INT8_C( 96),
         INT8_C( 78),  INT8_C(122),  INT8_C(  9), -INT8_C(124), -INT8_C( 36),  INT8_C( 79),     INT8_MAX,  INT8_C( 96) },
      { -INT8_C( 28), -INT8_C(  6), -INT8_C( 80), -INT8_C( 15),  INT8_C( 87), -INT8_C( 69),  INT8_C(101), -INT8_C( 84),
         INT8_C( 82), -INT8_C( 50),  INT8_C( 48), -INT8_C( 62),  INT8_C( 88), -INT8_C( 64),  INT8_C( 76), -INT8_C( 21) },
      {  INT8_C(119),     INT8_MAX,  INT8_C( 94),  INT8_C( 53), -INT8_C( 59), -INT8_C(118), -INT8_C( 46),  INT8_C( 12),
        -INT8_C( 96),  INT8_C( 72),  INT8_C( 57),  INT8_C( 70),  INT8_C( 52),  INT8_C( 15), -INT8_C( 53),  INT8_C( 75) } },
    { {  INT8_C( 69), -INT8_C(  6),  INT8_C( 48), -INT8_C( 76), -INT8_C( 55), -INT8_C( 99),  INT8_C( 20),  INT8_C( 24),
         INT8_C( 23),  INT8_C( 29), -INT8_C(100), -INT8_C( 12),  INT8_C(109),  INT8_C( 27),  INT8_C( 84),  INT8_C( 81) },
      {  INT8_C( 21),  INT8_C(  4),  INT8_C( 66),  INT8_C(108), -INT8_C( 65), -INT8_C( 89),  INT8_C( 24),  INT8_C( 18),
         INT8_C(117),  INT8_C( 73), -INT8_C( 44), -INT8_C( 50),  INT8_C(  9),  INT8_C( 32), -INT8_C( 71),  INT8_C( 79) },
      {  INT8_C( 90), -INT8_C(  2),  INT8_C(114),  INT8_C( 32), -INT8_C(120),  INT8_C( 68),  INT8_C( 44),  INT8_C( 42),
        -INT8_C(116),  INT8_C(102),  INT8_C(112), -INT8_C( 62),  INT8_C(118),  INT8_C( 59),  INT8_C( 13), -INT8_C( 96) } },
    { {  INT8_C( 26), -INT8_C( 23),  INT8_C(  3), -INT8_C( 29), -INT8_C(121),  INT8_C( 23), -INT8_C(  5), -INT8_C( 98),
         INT8_C( 53), -INT8_C(105), -INT8_C(110), -INT8_C( 94), -INT8_C( 77), -INT8_C( 26), -INT8_C( 13), -INT8_C( 56) },
      { -INT8_C( 21),  INT8_C( 53),  INT8_C( 53), -INT8_C( 86), -INT8_C( 36),  INT8_C( 77), -INT8_C( 68),  INT8_C( 81),
        -INT8_C(106), -INT8_C(112),  INT8_C( 31), -INT8_C( 96), -INT8_C( 80), -INT8_C( 39), -INT8_C( 17), -INT8_C( 54) },
      {  INT8_C(  5),  INT8_C( 30),  INT8_C( 56), -INT8_C(115),  INT8_C( 99),  INT8_C(100), -INT8_C( 73), -INT8_C( 17),
        -INT8_C( 53),  INT8_C( 39), -INT8_C( 79),  INT8_C( 66),  INT8_C( 99), -INT8_C( 65), -INT8_C( 30), -INT8_C(110) } },
    { { -INT8_C( 62), -INT8_C( 14), -INT8_C( 82),  INT8_C( 73),  INT8_C(  9), -INT8_C( 87), -INT8_C( 24),  INT8_C( 62),
         INT8_C( 65),  INT8_C(122), -INT8_C( 32), -INT8_C( 12),  INT8_C( 97), -INT8_C( 45), -INT8_C( 68),  INT8_C( 76) },
      {  INT8_C(  8), -INT8_C( 15), -INT8_C( 10), -INT8_C( 28),  INT8_C( 63), -INT8_C( 77),  INT8_C( 54), -INT8_C( 43),
         INT8_C( 67),  INT8_C( 85),  INT8_C(117), -INT8_C( 12),  INT8_C( 46),  INT8_C(100), -INT8_C( 66), -INT8_C( 15) },
      { -INT8_C( 54), -INT8_C( 29), -INT8_C( 92),  INT8_C( 45),  INT8_C( 72),  INT8_C( 92),  INT8_C( 30),  INT8_C( 19),
        -INT8_C(124), -INT8_C( 49),  INT8_C( 85), -INT8_C( 24), -INT8_C(113),  INT8_C( 55),  INT8_C(122),  INT8_C( 61) } },
    { {  INT8_C( 86),  INT8_C(108),  INT8_C( 58),  INT8_C( 96),  INT8_C( 22),  INT8_C( 34), -INT8_C( 98),  INT8_C( 87),
        -INT8_C( 99),     INT8_MAX,  INT8_C( 75), -INT8_C(  2),  INT8_C( 82),  INT8_C(  7),  INT8_C( 74),  INT8_C( 91) },
      { -INT8_C(  7),  INT8_C( 64),  INT8_C( 63),  INT8_C( 56), -INT8_C( 13),  INT8_C(117),  INT8_C( 13),  INT8_C( 55),
        -INT8_C( 53), -INT8_C(125),  INT8_C( 43), -INT8_C(  7), -INT8_C( 25), -INT8_C( 23), -INT8_C( 22),  INT8_C( 62) },
      {  INT8_C( 79), -INT8_C( 84),  INT8_C(121), -INT8_C(104),  INT8_C(  9), -INT8_C(105), -INT8_C( 85), -INT8_C(114),
         INT8_C(104),  INT8_C(  2),  INT8_C(118), -INT8_C(  9),  INT8_C( 57), -INT8_C( 16),  INT8_C( 52), -INT8_C(103) } }
  };

  // fputc('\n', stdout);
  // for (int i = 0 ; i < 8 ; i++) {
  //   simde_int8x16_t
  //     a = simde_test_arm_neon_random_i8x16(),
  //     b = simde_test_arm_neon_random_i8x16(),
  //     r = simde_vaddq_s8(a, b);
    
  //   simde_test_arm_neon_write_i8x16(2, a, SIMDE_TEST_VEC_POS_FIRST);
  //   simde_test_arm_neon_write_i8x16(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  //   simde_test_arm_neon_write_i8x16(2, r, SIMDE_TEST_VEC_POS_LAST);
  // }
  // return 1;

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
    { { -INT16_C(23396), -INT16_C(16905), -INT16_C(14579),  INT16_C( 3008), -INT16_C(12300),  INT16_C(24596), -INT16_C(20884),  INT16_C(29273) },
      {  INT16_C( 4071), -INT16_C(20277), -INT16_C(21319),  INT16_C(25386), -INT16_C( 4371), -INT16_C(11499),  INT16_C(14222),  INT16_C(11083) },
      { -INT16_C(19325),  INT16_C(28354),  INT16_C(29638),  INT16_C(28394), -INT16_C(16671),  INT16_C(13097), -INT16_C( 6662), -INT16_C(25180) } },
    { {  INT16_C(17116), -INT16_C( 5656), -INT16_C(22519), -INT16_C(  524),  INT16_C( 2167), -INT16_C( 7331), -INT16_C(18762), -INT16_C(25002) },
      {  INT16_C( 8646),  INT16_C(32590),  INT16_C(30925), -INT16_C(17694), -INT16_C( 1945), -INT16_C( 2675), -INT16_C(10193),  INT16_C( 2848) },
      {  INT16_C(25762),  INT16_C(26934),  INT16_C( 8406), -INT16_C(18218),  INT16_C(  222), -INT16_C(10006), -INT16_C(28955), -INT16_C(22154) } },
    { {  INT16_C( 2330),  INT16_C( 9461), -INT16_C( 5711),  INT16_C(10529),  INT16_C(32754), -INT16_C(22516),  INT16_C(25141), -INT16_C( 1210) },
      { -INT16_C(27517),  INT16_C(20602),  INT16_C(23821),  INT16_C(29706), -INT16_C(26795), -INT16_C(31639), -INT16_C(30097), -INT16_C(30064) },
      { -INT16_C(25187),  INT16_C(30063),  INT16_C(18110), -INT16_C(25301),  INT16_C( 5959),  INT16_C(11381), -INT16_C( 4956), -INT16_C(31274) } },
    { { -INT16_C(31341),  INT16_C(17582), -INT16_C(12434),  INT16_C(24685),  INT16_C(31310), -INT16_C(31735),  INT16_C(20444),  INT16_C(24703) },
      { -INT16_C( 1308), -INT16_C( 3664), -INT16_C(17577), -INT16_C(21403), -INT16_C(12718), -INT16_C(15824), -INT16_C(16296), -INT16_C( 5300) },
      { -INT16_C(32649),  INT16_C(13918), -INT16_C(30011),  INT16_C( 3282),  INT16_C(18592),  INT16_C(17977),  INT16_C( 4148),  INT16_C(19403) } },
    { { -INT16_C( 1467), -INT16_C(19408), -INT16_C(25143),  INT16_C( 6164),  INT16_C( 7447), -INT16_C( 2916),  INT16_C( 7021),  INT16_C(20820) },
      {  INT16_C( 1045),  INT16_C(27714), -INT16_C(22593),  INT16_C( 4632),  INT16_C(18805), -INT16_C(12588),  INT16_C( 8201),  INT16_C(20409) },
      { -INT16_C(  422),  INT16_C( 8306),  INT16_C(17800),  INT16_C(10796),  INT16_C(26252), -INT16_C(15504),  INT16_C(15222), -INT16_C(24307) } },
    { { -INT16_C( 5862), -INT16_C( 7421),  INT16_C( 6023), -INT16_C(24837), -INT16_C(26827), -INT16_C(23918), -INT16_C( 6477), -INT16_C(14093) },
      {  INT16_C(13803), -INT16_C(21963),  INT16_C(19932),  INT16_C(20924), -INT16_C(28522), -INT16_C(24545), -INT16_C( 9808), -INT16_C(13585) },
      {  INT16_C( 7941), -INT16_C(29384),  INT16_C(25955), -INT16_C( 3913),  INT16_C(10187),  INT16_C(17073), -INT16_C(16285), -INT16_C(27678) } },
    { { -INT16_C( 3390),  INT16_C(18862), -INT16_C(22263),  INT16_C(16104),  INT16_C(31297), -INT16_C( 2848), -INT16_C(11423),  INT16_C(19644) },
      { -INT16_C( 3832), -INT16_C( 6922), -INT16_C(19649), -INT16_C(10954),  INT16_C(21827), -INT16_C( 2955),  INT16_C(25646), -INT16_C( 3650) },
      { -INT16_C( 7222),  INT16_C(11940),  INT16_C(23624),  INT16_C( 5150), -INT16_C(12412), -INT16_C( 5803),  INT16_C(14223),  INT16_C(15994) } },
    { {  INT16_C(27734),  INT16_C(24634),  INT16_C( 8726),  INT16_C(22430),  INT16_C(32669), -INT16_C(  437),  INT16_C( 1874),  INT16_C(23370) },
      {  INT16_C(16633),  INT16_C(14399),  INT16_C(30195),  INT16_C(14093), -INT16_C(31797), -INT16_C( 1749), -INT16_C( 5657),  INT16_C(16106) },
      { -INT16_C(21169), -INT16_C(26503), -INT16_C(26615), -INT16_C(29013),  INT16_C(  872), -INT16_C( 2186), -INT16_C( 3783), -INT16_C(26060) } }
  };

  // fputc('\n', stdout);
  // for (int i = 0 ; i < 8 ; i++) {
  //   simde_int16x8_t
  //     a = simde_test_arm_neon_random_i16x8(),
  //     b = simde_test_arm_neon_random_i16x8(),
  //     r = simde_vaddq_s16(a, b);
    
  //   simde_test_arm_neon_write_i16x8(2, a, SIMDE_TEST_VEC_POS_FIRST);
  //   simde_test_arm_neon_write_i16x8(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  //   simde_test_arm_neon_write_i16x8(2, r, SIMDE_TEST_VEC_POS_LAST);
  // }
  // return 1;

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
    { { -INT32_C(1107843940),  INT32_C( 197183245),  INT32_C(1611976692),  INT32_C(1918479980) },
      { -INT32_C(1328869401),  INT32_C(1663741113), -INT32_C( 753537299),  INT32_C( 726349710) },
      {  INT32_C(1858253955),  INT32_C(1860924358),  INT32_C( 858439393), -INT32_C(1650137606) } },
    { { -INT32_C( 370654500), -INT32_C(  34297847), -INT32_C( 480442249), -INT32_C(1638484298) },
      {  INT32_C(2135826886), -INT32_C(1159563059), -INT32_C( 175245209),  INT32_C( 186701871) },
      {  INT32_C(1765172386), -INT32_C(1193860906), -INT32_C( 655687458), -INT32_C(1451782427) } },
    { {  INT32_C( 620038426),  INT32_C( 690088369), -INT32_C(1475575822), -INT32_C(  79273419) },
      {  INT32_C(1350210691),  INT32_C(1946836237), -INT32_C(2073454763), -INT32_C(1970238865) },
      {  INT32_C(1970249117), -INT32_C(1658042690),  INT32_C( 745936711), -INT32_C(2049512284) } },
    { {  INT32_C(1152288147),  INT32_C(1617809262), -INT32_C(2079753650),  INT32_C(1618956252) },
      { -INT32_C( 240059676), -INT32_C(1402619049), -INT32_C(1036988846), -INT32_C( 347291560) },
      {  INT32_C( 912228471),  INT32_C( 215190213),  INT32_C(1178224800),  INT32_C(1271664692) } },
    { { -INT32_C(1271858619),  INT32_C( 404004297), -INT32_C( 191095529),  INT32_C(1364466541) },
      {  INT32_C(1816265749),  INT32_C( 303605695), -INT32_C( 824948363),  INT32_C(1337532425) },
      {  INT32_C( 544407130),  INT32_C( 707609992), -INT32_C(1016043892), -INT32_C(1592968330) } },
    { { -INT32_C( 486282982), -INT32_C(1627711609), -INT32_C(1567451339), -INT32_C( 923539789) },
      { -INT32_C(1439353365),  INT32_C(1371295196), -INT32_C(1608544106), -INT32_C( 890250832) },
      { -INT32_C(1925636347), -INT32_C( 256416413),  INT32_C(1118971851), -INT32_C(1813790621) } },
    { {  INT32_C(1236202178),  INT32_C(1055435017), -INT32_C( 186615231),  INT32_C(1287443297) },
      { -INT32_C( 453578488), -INT32_C( 717835457), -INT32_C( 193637053), -INT32_C( 239180754) },
      {  INT32_C( 782623690),  INT32_C( 337599560), -INT32_C( 380252284),  INT32_C(1048262543) } },
    { {  INT32_C(1614441558),  INT32_C(1469981206), -INT32_C(  28606563),  INT32_C(1531578194) },
      {  INT32_C( 943669497),  INT32_C( 923629043), -INT32_C( 114588725),  INT32_C(1055582695) },
      { -INT32_C(1736856241), -INT32_C(1901357047), -INT32_C( 143195288), -INT32_C(1707806407) } }
  };

  // fputc('\n', stdout);
  // for (int i = 0 ; i < 8 ; i++) {
  //   simde_int32x4_t
  //     a = simde_test_arm_neon_random_i32x4(),
  //     b = simde_test_arm_neon_random_i32x4(),
  //     r = simde_vaddq_s32(a, b);
    
  //   simde_test_arm_neon_write_i32x4(2, a, SIMDE_TEST_VEC_POS_FIRST);
  //   simde_test_arm_neon_write_i32x4(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  //   simde_test_arm_neon_write_i32x4(2, r, SIMDE_TEST_VEC_POS_LAST);
  // }
  // return 1;

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
    { {  INT64_C( 587610080254985523),  INT64_C(5250589190473620593) },
      {  INT64_C(8937501781235918424), -INT64_C(2086302765174859017) },
      { -INT64_C(8921632212218647669),  INT64_C(3164286425298761576) } },
    { {  INT64_C(2433421201982887035), -INT64_C(6615570922803268389) },
      { -INT64_C(8742597872290812757), -INT64_C( 721732106520525977) },
      { -INT64_C(6309176670307925722), -INT64_C(7337303029323794366) } },
    { {  INT64_C(3371356992964793336),  INT64_C(2583453714561217259) },
      {  INT64_C(6090836939443003250),  INT64_C(4463462251691270274) },
      { -INT64_C(8984550141301755030),  INT64_C(7046915966252487533) } },
    { {  INT64_C( 430849244008915834), -INT64_C(4036608083051736991) },
      { -INT64_C(3443197289382261003), -INT64_C(8921423007083355218) },
      { -INT64_C(3012348045373345169),  INT64_C(5488712983574459407) } },
    { {  INT64_C(2701961608683328864), -INT64_C(4145288777981576357) },
      {  INT64_C(4424470586955743304),  INT64_C(5841556777953407875) },
      {  INT64_C(7126432195639072168),  INT64_C(1696267999971831518) } },
    { {  INT64_C( 531226484145873269), -INT64_C(6945341896495964922) },
      { -INT64_C(6252233065897834896),  INT64_C(4688326152504634318) },
      { -INT64_C(5721006581751961627), -INT64_C(2257015743991330604) } },
    { {  INT64_C(3196951168680713129), -INT64_C(5391194383791745736) },
      { -INT64_C(3623163500748905497), -INT64_C(2420794522594382246) },
      { -INT64_C( 426212332068192368), -INT64_C(7811988906386127982) } },
    { { -INT64_C( 807672943865437577),  INT64_C(6242184177786277542) },
      { -INT64_C(7070620344852917484),  INT64_C(9159804907036044298) },
      { -INT64_C(7878293288718355061), -INT64_C(3044754988887229776) } }
  };

  // fputc('\n', stdout);
  // for (int i = 0 ; i < 8 ; i++) {
  //   simde_int64x2_t
  //     a = simde_test_arm_neon_random_i64x2(),
  //     b = simde_test_arm_neon_random_i64x2(),
  //     r = simde_vaddq_s64(a, b);
    
  //   simde_test_arm_neon_write_i64x2(2, a, SIMDE_TEST_VEC_POS_FIRST);
  //   simde_test_arm_neon_write_i64x2(2, b, SIMDE_TEST_VEC_POS_MIDDLE);
  //   simde_test_arm_neon_write_i64x2(2, r, SIMDE_TEST_VEC_POS_LAST);
  // }
  // return 1;

  for (size_t i = 0 ; i < (sizeof(test_vec) / sizeof(test_vec[0])) ; i++) {
    simde_int64x2_t
      a = simde_vld1q_s64(test_vec[i].a),
      b = simde_vld1q_s64(test_vec[i].b),
      r = simde_vaddq_s64(a, b);
    simde_test_arm_neon_assert_equal_i64x2(r, simde_vld1q_s64(test_vec[i].r));
  }

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

#include <test/arm/neon/test-neon-footer.h>
