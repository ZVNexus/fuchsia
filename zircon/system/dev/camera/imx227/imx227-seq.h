// Copyright 2018 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include <ddktl/protocol/ispimpl.h>

namespace camera {

typedef struct init_seq_fmt {
    uint16_t address;
    uint8_t value;
    uint8_t mask;
    uint8_t len;
} init_seq_fmt_t;

// -----------------------//
//      INIT SEQUENCES
// -----------------------//

constexpr uint8_t kSENSOR_IMX227_SEQUENCE_DEFAULT_PREVIEW = 0;
constexpr uint8_t kSENSOR_IMX227_SEQUENCE_TESTPATTERN = 1;
constexpr uint8_t kSENSOR_IMX227_SEQUENCE_TESTPATTERN_960M = 2;
constexpr uint8_t kSENSOR_IMX227_SEQUENCE_1080P_TESTPATTERN = 3;
constexpr uint8_t kSENSOR_IMX227_SEQUENCE_1080P_PREVIEW = 4;
constexpr uint8_t kSENSOR_IMX227_SEQUENCE_DEFAULT_FULLSENSOR_PREVIEW = 5;

constexpr init_seq_fmt_t setting_2200_2720_2lane_996mbps_30fps[] = {
    {0x0136, 0x18, 0xFF, 1},
    {0x0137, 0x00, 0xFF, 1},
    {0xAE20, 0x00, 0xFF, 1},
    {0x463B, 0x30, 0xFF, 1},
    {0x463E, 0x05, 0xFF, 1},
    {0x4612, 0x66, 0xFF, 1},
    {0x4815, 0x65, 0xFF, 1},
    {0x4991, 0x00, 0xFF, 1},
    {0x4992, 0x01, 0xFF, 1},
    {0x4993, 0xFF, 0xFF, 1},
    {0x458B, 0x00, 0xFF, 1},
    {0x452A, 0x02, 0xFF, 1},
    {0x4A7C, 0x00, 0xFF, 1},
    {0x4A7D, 0x1C, 0xFF, 1},
    {0x4A7E, 0x00, 0xFF, 1},
    {0x4A7F, 0x17, 0xFF, 1},
    {0x462C, 0x2E, 0xFF, 1},
    {0x461B, 0x28, 0xFF, 1},
    {0x4663, 0x29, 0xFF, 1},
    {0x461A, 0x7C, 0xFF, 1},
    {0x4619, 0x28, 0xFF, 1},
    {0x4667, 0x22, 0xFF, 1},
    {0x466B, 0x23, 0xFF, 1},
    {0x4D16, 0x00, 0xFF, 1},
    {0x6204, 0x01, 0xFF, 1},
    {0x6209, 0x00, 0xFF, 1},
    {0x621F, 0x01, 0xFF, 1},
    {0x621E, 0x10, 0xFF, 1},
    {0x48E3, 0x82, 0xFF, 1},
    {0x0114, 0x01, 0xFF, 1},
    {0x0340, 0x0A, 0xFF, 1},
    {0x0341, 0xE0, 0xFF, 1},
    {0x0342, 0x10, 0xFF, 1},
    {0x0343, 0x00, 0xFF, 1},
    {0x0344, 0x00, 0xFF, 1},
    {0x0345, 0x64, 0xFF, 1},
    {0x0346, 0x00, 0xFF, 1},
    {0x0347, 0x00, 0xFF, 1},
    {0x0348, 0x08, 0xFF, 1},
    {0x0349, 0xFB, 0xFF, 1},
    {0x034A, 0x0A, 0xFF, 1},
    {0x034B, 0x9F, 0xFF, 1},
    {0x0381, 0x01, 0xFF, 1},
    {0x0383, 0x01, 0xFF, 1},
    {0x0385, 0x01, 0xFF, 1},
    {0x0387, 0x01, 0xFF, 1},
    {0x0900, 0x00, 0xFF, 1},
    {0x0901, 0x00, 0xFF, 1},
    {0x0112, 0x0A, 0xFF, 1},
    {0x0113, 0x0A, 0xFF, 1},
    {0x034C, 0x08, 0xFF, 1},
    {0x034D, 0x98, 0xFF, 1},
    {0x034E, 0x0A, 0xFF, 1},
    {0x034F, 0xA0, 0xFF, 1},
    {0x0408, 0x00, 0xFF, 1},
    {0x0409, 0x00, 0xFF, 1},
    {0x040A, 0x00, 0xFF, 1},
    {0x040B, 0x00, 0xFF, 1},
    {0x040C, 0x08, 0xFF, 1},
    {0x040D, 0x98, 0xFF, 1},
    {0x040E, 0x0A, 0xFF, 1},
    {0x040F, 0xA0, 0xFF, 1},
    {0x0301, 0x07, 0xFF, 1},
    {0x0303, 0x02, 0xFF, 1},
    {0x0305, 0x04, 0xFF, 1},
    {0x0306, 0x00, 0xFF, 1},
    {0x0307, 0xC8, 0xFF, 1},
    {0x0309, 0x0A, 0xFF, 1},
    {0x030B, 0x01, 0xFF, 1},
    {0x030D, 0x0C, 0xFF, 1}, // Update for 996 mbps
    {0x030E, 0x01, 0xFF, 1}, // Update for 996 mbps
    {0x030F, 0xF2, 0xFF, 1}, // Update for 996 mbps
    {0x0310, 0x01, 0xFF, 1},
    {0x0820, 0x07, 0xFF, 1},
    {0x0821, 0xD0, 0xFF, 1},
    {0x0822, 0x00, 0xFF, 1},
    {0x0823, 0x00, 0xFF, 1},
    {0x3000, 0x00, 0xFF, 1},
    {0x3002, 0x01, 0xFF, 1},
    {0x3003, 0x35, 0xFF, 1},
    {0x6259, 0x06, 0xFF, 1},
    {0x0202, 0x0A, 0xFF, 1}, // int time
    {0x0203, 0xDE, 0xFF, 1},
    {0x0204, 0x00, 0xFF, 1},
    {0x0205, 0xC0, 0xFF, 1}, // a gain
    {0x020E, 0x01, 0xFF, 1},
    {0x020F, 0x00, 0xFF, 1},
    {0x0000, 0x0000, 0x0000, 0x0000},
};

constexpr init_seq_fmt_t setting_2200_2720_2lane_996mbps_30fps_test_pattern[] = {
    {0x0136, 0x18, 0xFF, 1},
    {0x0137, 0x00, 0xFF, 1},
    {0xAE20, 0x00, 0xFF, 1},
    {0x463B, 0x30, 0xFF, 1},
    {0x463E, 0x05, 0xFF, 1},
    {0x4612, 0x66, 0xFF, 1},
    {0x4815, 0x65, 0xFF, 1},
    {0x4991, 0x00, 0xFF, 1},
    {0x4992, 0x01, 0xFF, 1},
    {0x4993, 0xFF, 0xFF, 1},
    {0x458B, 0x00, 0xFF, 1},
    {0x452A, 0x02, 0xFF, 1},
    {0x4A7C, 0x00, 0xFF, 1},
    {0x4A7D, 0x1C, 0xFF, 1},
    {0x4A7E, 0x00, 0xFF, 1},
    {0x4A7F, 0x17, 0xFF, 1},
    {0x462C, 0x2E, 0xFF, 1},
    {0x461B, 0x28, 0xFF, 1},
    {0x4663, 0x29, 0xFF, 1},
    {0x461A, 0x7C, 0xFF, 1},
    {0x4619, 0x28, 0xFF, 1},
    {0x4667, 0x22, 0xFF, 1},
    {0x466B, 0x23, 0xFF, 1},
    {0x4D16, 0x00, 0xFF, 1},
    {0x6204, 0x01, 0xFF, 1},
    {0x6209, 0x00, 0xFF, 1},
    {0x621F, 0x01, 0xFF, 1},
    {0x621E, 0x10, 0xFF, 1},
    {0x48E3, 0x82, 0xFF, 1},
    {0x0114, 0x01, 0xFF, 1},
    {0x0340, 0x0A, 0xFF, 1},
    {0x0341, 0xE0, 0xFF, 1},
    {0x0342, 0x10, 0xFF, 1},
    {0x0343, 0x00, 0xFF, 1},
    {0x0344, 0x00, 0xFF, 1},
    {0x0345, 0x64, 0xFF, 1},
    {0x0346, 0x00, 0xFF, 1},
    {0x0347, 0x00, 0xFF, 1},
    {0x0348, 0x08, 0xFF, 1},
    {0x0349, 0xFB, 0xFF, 1},
    {0x034A, 0x0A, 0xFF, 1},
    {0x034B, 0x9F, 0xFF, 1},
    {0x0381, 0x01, 0xFF, 1},
    {0x0383, 0x01, 0xFF, 1},
    {0x0385, 0x01, 0xFF, 1},
    {0x0387, 0x01, 0xFF, 1},
    {0x0900, 0x00, 0xFF, 1},
    {0x0901, 0x00, 0xFF, 1},
    {0x0112, 0x0A, 0xFF, 1},
    {0x0113, 0x0A, 0xFF, 1},
    {0x034C, 0x08, 0xFF, 1},
    {0x034D, 0x98, 0xFF, 1},
    {0x034E, 0x0A, 0xFF, 1},
    {0x034F, 0xA0, 0xFF, 1},
    {0x0408, 0x00, 0xFF, 1},
    {0x0409, 0x00, 0xFF, 1},
    {0x040A, 0x00, 0xFF, 1},
    {0x040B, 0x00, 0xFF, 1},
    {0x040C, 0x08, 0xFF, 1},
    {0x040D, 0x98, 0xFF, 1},
    {0x040E, 0x0A, 0xFF, 1},
    {0x040F, 0xA0, 0xFF, 1},
    {0x0301, 0x07, 0xFF, 1},
    {0x0303, 0x02, 0xFF, 1},
    {0x0305, 0x04, 0xFF, 1},
    {0x0306, 0x00, 0xFF, 1},
    {0x0307, 0xC8, 0xFF, 1},
    {0x0309, 0x0A, 0xFF, 1},
    {0x030B, 0x01, 0xFF, 1},
    {0x030D, 0x0C, 0xFF, 1}, // Update for 996 mbps
    {0x030E, 0x01, 0xFF, 1}, // Update for 996 mbps
    {0x030F, 0xF2, 0xFF, 1}, // Update for 996 mbps
    {0x0310, 0x01, 0xFF, 1},
    {0x0820, 0x07, 0xFF, 1},
    {0x0821, 0xD0, 0xFF, 1},
    {0x0822, 0x00, 0xFF, 1},
    {0x0823, 0x00, 0xFF, 1},
    {0x3000, 0x00, 0xFF, 1},
    {0x3002, 0x01, 0xFF, 1},
    {0x3003, 0x35, 0xFF, 1},
    {0x6259, 0x06, 0xFF, 1},
    {0x0600, 0x00, 0xFF, 1},
    {0x0601, 0x03, 0xFF, 1},
    {0x0000, 0x0000, 0x0000, 0x0000},
};

constexpr init_seq_fmt_t setting_2200_2720_2lane_960m_30fps_test_pattern[] = {
    {0x0136, 0x18, 0xFF, 1},
    {0x0137, 0x00, 0xFF, 1},
    {0xAE20, 0x00, 0xFF, 1},
    {0x463B, 0x30, 0xFF, 1},
    {0x463E, 0x05, 0xFF, 1},
    {0x4612, 0x66, 0xFF, 1},
    {0x4815, 0x65, 0xFF, 1},
    {0x4991, 0x00, 0xFF, 1},
    {0x4992, 0x01, 0xFF, 1},
    {0x4993, 0xFF, 0xFF, 1},
    {0x458B, 0x00, 0xFF, 1},
    {0x452A, 0x02, 0xFF, 1},
    {0x4A7C, 0x00, 0xFF, 1},
    {0x4A7D, 0x1C, 0xFF, 1},
    {0x4A7E, 0x00, 0xFF, 1},
    {0x4A7F, 0x17, 0xFF, 1},
    {0x462C, 0x2E, 0xFF, 1},
    {0x461B, 0x28, 0xFF, 1},
    {0x4663, 0x29, 0xFF, 1},
    {0x461A, 0x7C, 0xFF, 1},
    {0x4619, 0x28, 0xFF, 1},
    {0x4667, 0x22, 0xFF, 1},
    {0x466B, 0x23, 0xFF, 1},
    {0x4D16, 0x00, 0xFF, 1},
    {0x6204, 0x01, 0xFF, 1},
    {0x6209, 0x00, 0xFF, 1},
    {0x621F, 0x01, 0xFF, 1},
    {0x621E, 0x10, 0xFF, 1},
    {0x48E3, 0x82, 0xFF, 1},
    {0x0114, 0x01, 0xFF, 1},
    {0x0340, 0x0A, 0xFF, 1},
    {0x0341, 0xC0, 0xFF, 1},
    {0x0342, 0x10, 0xFF, 1},
    {0x0343, 0x38, 0xFF, 1},
    {0x0344, 0x00, 0xFF, 1},
    {0x0345, 0x64, 0xFF, 1},
    {0x0346, 0x00, 0xFF, 1},
    {0x0347, 0x00, 0xFF, 1},
    {0x0348, 0x08, 0xFF, 1},
    {0x0349, 0xFB, 0xFF, 1},
    {0x034A, 0x0A, 0xFF, 1},
    {0x034B, 0x9F, 0xFF, 1},
    {0x0381, 0x01, 0xFF, 1},
    {0x0383, 0x01, 0xFF, 1},
    {0x0385, 0x01, 0xFF, 1},
    {0x0387, 0x01, 0xFF, 1},
    {0x0900, 0x00, 0xFF, 1},
    {0x0901, 0x00, 0xFF, 1},
    {0x0112, 0x0A, 0xFF, 1},
    {0x0113, 0x0A, 0xFF, 1},
    {0x034C, 0x08, 0xFF, 1},
    {0x034D, 0x98, 0xFF, 1},
    {0x034E, 0x0A, 0xFF, 1},
    {0x034F, 0xA0, 0xFF, 1},
    {0x0408, 0x00, 0xFF, 1},
    {0x0409, 0x00, 0xFF, 1},
    {0x040A, 0x00, 0xFF, 1},
    {0x040B, 0x00, 0xFF, 1},
    {0x040C, 0x08, 0xFF, 1},
    {0x040D, 0x98, 0xFF, 1},
    {0x040E, 0x0A, 0xFF, 1},
    {0x040F, 0xA0, 0xFF, 1},
    {0x0301, 0x07, 0xFF, 1},
    {0x0303, 0x02, 0xFF, 1},
    {0x0305, 0x04, 0xFF, 1},
    {0x0306, 0x00, 0xFF, 1},
    {0x0307, 0xC8, 0xFF, 1},
    {0x0309, 0x0A, 0xFF, 1},
    {0x030B, 0x01, 0xFF, 1},
    {0x030D, 0x0F, 0xFF, 1},
    {0x030E, 0x02, 0xFF, 1},
    {0x030F, 0x58, 0xFF, 1},
    {0x0310, 0x01, 0xFF, 1},
    {0x0820, 0x07, 0xFF, 1},
    {0x0821, 0x80, 0xFF, 1},
    {0x0822, 0x00, 0xFF, 1},
    {0x0823, 0x00, 0xFF, 1},
    {0x3000, 0x00, 0xFF, 1},
    {0x3002, 0x01, 0xFF, 1},
    {0x3003, 0x35, 0xFF, 1},
    {0x6259, 0x06, 0xFF, 1},
    {0x0600, 0x00, 0xFF, 1},
    {0x0601, 0x03, 0xFF, 1},
    {0x0000, 0x0000, 0x0000, 0x0000},
};

constexpr init_seq_fmt_t setting_1920_1080_2lane_996mbps_30fps_test_pattern[] = {
    {0x0136, 0x18, 0xFF, 1},
    {0x0137, 0x00, 0xFF, 1},
    {0xAE20, 0x00, 0xFF, 1},
    {0x463B, 0x30, 0xFF, 1},
    {0x463E, 0x05, 0xFF, 1},
    {0x4612, 0x66, 0xFF, 1},
    {0x4815, 0x65, 0xFF, 1},
    {0x4991, 0x00, 0xFF, 1},
    {0x4992, 0x01, 0xFF, 1},
    {0x4993, 0xFF, 0xFF, 1},
    {0x458B, 0x00, 0xFF, 1},
    {0x452A, 0x02, 0xFF, 1},
    {0x4A7C, 0x00, 0xFF, 1},
    {0x4A7D, 0x1C, 0xFF, 1},
    {0x4A7E, 0x00, 0xFF, 1},
    {0x4A7F, 0x17, 0xFF, 1},
    {0x462C, 0x2E, 0xFF, 1},
    {0x461B, 0x28, 0xFF, 1},
    {0x4663, 0x29, 0xFF, 1},
    {0x461A, 0x7C, 0xFF, 1},
    {0x4619, 0x28, 0xFF, 1},
    {0x4667, 0x22, 0xFF, 1},
    {0x466B, 0x23, 0xFF, 1},
    {0x4D16, 0x00, 0xFF, 1},
    {0x6204, 0x01, 0xFF, 1},
    {0x6209, 0x00, 0xFF, 1},
    {0x621F, 0x01, 0xFF, 1},
    {0x621E, 0x10, 0xFF, 1},
    {0x48E3, 0x82, 0xFF, 1},
    {0x0114, 0x01, 0xFF, 1},
    {0x0340, 0x06, 0xFF, 1},
    {0x0341, 0x08, 0xFF, 1},
    {0x0342, 0x0E, 0xFF, 1},
    {0x0343, 0x70, 0xFF, 1},
    {0x0344, 0x00, 0xFF, 1},
    {0x0345, 0xF0, 0xFF, 1},
    {0x0346, 0x03, 0xFF, 1},
    {0x0347, 0x34, 0xFF, 1},
    {0x0348, 0x08, 0xFF, 1},
    {0x0349, 0x6F, 0xFF, 1},
    {0x034A, 0x07, 0xFF, 1},
    {0x034B, 0x6B, 0xFF, 1},
    {0x0381, 0x01, 0xFF, 1},
    {0x0383, 0x01, 0xFF, 1},
    {0x0385, 0x01, 0xFF, 1},
    {0x0387, 0x01, 0xFF, 1},
    {0x0900, 0x00, 0xFF, 1},
    {0x0901, 0x00, 0xFF, 1},
    {0x0112, 0x0A, 0xFF, 1},
    {0x0113, 0x0A, 0xFF, 1},
    {0x034C, 0x07, 0xFF, 1},
    {0x034D, 0x80, 0xFF, 1},
    {0x034E, 0x04, 0xFF, 1},
    {0x034F, 0x38, 0xFF, 1},
    {0x0408, 0x00, 0xFF, 1},
    {0x0409, 0x00, 0xFF, 1},
    {0x040A, 0x00, 0xFF, 1},
    {0x040B, 0x00, 0xFF, 1},
    {0x040C, 0x07, 0xFF, 1},
    {0x040D, 0x80, 0xFF, 1},
    {0x040E, 0x04, 0xFF, 1},
    {0x040F, 0x38, 0xFF, 1},
    {0x0301, 0x07, 0xFF, 1},
    {0x0303, 0x02, 0xFF, 1},
    {0x0305, 0x04, 0xFF, 1},
    {0x0306, 0x00, 0xFF, 1},
    {0x0307, 0xC8, 0xFF, 1},
    {0x0309, 0x0A, 0xFF, 1},
    {0x030B, 0x01, 0xFF, 1},
    {0x030D, 0x0C, 0xFF, 1}, // Update for 996 mbps
    {0x030E, 0x01, 0xFF, 1}, // Update for 996 mbps
    {0x030F, 0xF2, 0xFF, 1}, // Update for 996 mbps
    {0x0310, 0x01, 0xFF, 1},
    {0x0820, 0x07, 0xFF, 1},
    {0x0821, 0xD0, 0xFF, 1},
    {0x0822, 0x00, 0xFF, 1},
    {0x0823, 0x00, 0xFF, 1},
    {0x3000, 0x00, 0xFF, 1},
    {0x3002, 0x01, 0xFF, 1},
    {0x3003, 0x04, 0xFF, 1},
    {0x6259, 0x05, 0xFF, 1},
    {0x0600, 0x00, 0xFF, 1},
    {0x0601, 0x04, 0xFF, 1},
    {0x0000, 0x0000, 0x0000, 0x0000},
};

constexpr init_seq_fmt_t setting_1920_1080_2lane_996mbps_30fps[] = {
    {0x0136, 0x18, 0xFF, 1},
    {0x0137, 0x00, 0xFF, 1},
    {0xAE20, 0x00, 0xFF, 1},
    {0x463B, 0x30, 0xFF, 1},
    {0x463E, 0x05, 0xFF, 1},
    {0x4612, 0x66, 0xFF, 1},
    {0x4815, 0x65, 0xFF, 1},
    {0x4991, 0x00, 0xFF, 1},
    {0x4992, 0x01, 0xFF, 1},
    {0x4993, 0xFF, 0xFF, 1},
    {0x458B, 0x00, 0xFF, 1},
    {0x452A, 0x02, 0xFF, 1},
    {0x4A7C, 0x00, 0xFF, 1},
    {0x4A7D, 0x1C, 0xFF, 1},
    {0x4A7E, 0x00, 0xFF, 1},
    {0x4A7F, 0x17, 0xFF, 1},
    {0x462C, 0x2E, 0xFF, 1},
    {0x461B, 0x28, 0xFF, 1},
    {0x4663, 0x29, 0xFF, 1},
    {0x461A, 0x7C, 0xFF, 1},
    {0x4619, 0x28, 0xFF, 1},
    {0x4667, 0x22, 0xFF, 1},
    {0x466B, 0x23, 0xFF, 1},
    {0x4D16, 0x00, 0xFF, 1},
    {0x6204, 0x01, 0xFF, 1},
    {0x6209, 0x00, 0xFF, 1},
    {0x621F, 0x01, 0xFF, 1},
    {0x621E, 0x10, 0xFF, 1},
    {0x48E3, 0x82, 0xFF, 1},
    {0x0114, 0x01, 0xFF, 1},
    {0x0340, 0x06, 0xFF, 1},
    {0x0341, 0x08, 0xFF, 1},
    {0x0342, 0x0E, 0xFF, 1},
    {0x0343, 0x70, 0xFF, 1},
    {0x0344, 0x00, 0xFF, 1},
    {0x0345, 0xF0, 0xFF, 1},
    {0x0346, 0x03, 0xFF, 1},
    {0x0347, 0x34, 0xFF, 1},
    {0x0348, 0x08, 0xFF, 1},
    {0x0349, 0x6F, 0xFF, 1},
    {0x034A, 0x07, 0xFF, 1},
    {0x034B, 0x6B, 0xFF, 1},
    {0x0381, 0x01, 0xFF, 1},
    {0x0383, 0x01, 0xFF, 1},
    {0x0385, 0x01, 0xFF, 1},
    {0x0387, 0x01, 0xFF, 1},
    {0x0900, 0x00, 0xFF, 1},
    {0x0901, 0x00, 0xFF, 1},
    {0x0112, 0x0A, 0xFF, 1},
    {0x0113, 0x0A, 0xFF, 1},
    {0x034C, 0x07, 0xFF, 1},
    {0x034D, 0x80, 0xFF, 1},
    {0x034E, 0x04, 0xFF, 1},
    {0x034F, 0x38, 0xFF, 1},
    {0x0408, 0x00, 0xFF, 1},
    {0x0409, 0x00, 0xFF, 1},
    {0x040A, 0x00, 0xFF, 1},
    {0x040B, 0x00, 0xFF, 1},
    {0x040C, 0x07, 0xFF, 1},
    {0x040D, 0x80, 0xFF, 1},
    {0x040E, 0x04, 0xFF, 1},
    {0x040F, 0x38, 0xFF, 1},
    {0x0301, 0x07, 0xFF, 1},
    {0x0303, 0x02, 0xFF, 1},
    {0x0305, 0x04, 0xFF, 1},
    {0x0306, 0x00, 0xFF, 1},
    {0x0307, 0xC8, 0xFF, 1},
    {0x0309, 0x0A, 0xFF, 1},
    {0x030B, 0x01, 0xFF, 1},
    {0x030D, 0x0C, 0xFF, 1}, // Update for 996 mbps
    {0x030E, 0x01, 0xFF, 1}, // Update for 996 mbps
    {0x030F, 0xF2, 0xFF, 1}, // Update for 996 mbps
    {0x0310, 0x01, 0xFF, 1},
    {0x0820, 0x07, 0xFF, 1},
    {0x0821, 0xD0, 0xFF, 1},
    {0x0822, 0x00, 0xFF, 1},
    {0x0823, 0x00, 0xFF, 1},
    {0x3000, 0x00, 0xFF, 1},
    {0x3002, 0x01, 0xFF, 1},
    {0x3003, 0x04, 0xFF, 1},
    {0x6259, 0x05, 0xFF, 1},
    {0x0202, 0x0C, 0xFF, 1}, // int time
    {0x0203, 0x0E, 0xFF, 1},
    {0x0204, 0x00, 0xFF, 1},
    {0x0205, 0xE0, 0xFF, 1}, // a gain
    {0x020E, 0x01, 0xFF, 1},
    {0x020F, 0x00, 0xFF, 1},
    {0x0000, 0x0000, 0x0000, 0x0000},
};

constexpr init_seq_fmt_t setting_2400_2720_2lane_996mbps_28fps[] = {
    {0x0136, 0x18, 0xFF, 1},
    {0x0137, 0x00, 0xFF, 1},
    {0xAE20, 0x00, 0xFF, 1},
    {0x463B, 0x30, 0xFF, 1},
    {0x463E, 0x05, 0xFF, 1},
    {0x4612, 0x66, 0xFF, 1},
    {0x4815, 0x65, 0xFF, 1},
    {0x4991, 0x00, 0xFF, 1},
    {0x4992, 0x01, 0xFF, 1},
    {0x4993, 0xFF, 0xFF, 1},
    {0x458B, 0x00, 0xFF, 1},
    {0x452A, 0x02, 0xFF, 1},
    {0x4A7C, 0x00, 0xFF, 1},
    {0x4A7D, 0x1C, 0xFF, 1},
    {0x4A7E, 0x00, 0xFF, 1},
    {0x4A7F, 0x17, 0xFF, 1},
    {0x462C, 0x2E, 0xFF, 1},
    {0x461B, 0x28, 0xFF, 1},
    {0x4663, 0x29, 0xFF, 1},
    {0x461A, 0x7C, 0xFF, 1},
    {0x4619, 0x28, 0xFF, 1},
    {0x4667, 0x22, 0xFF, 1},
    {0x466B, 0x23, 0xFF, 1},
    {0x4D16, 0x00, 0xFF, 1},
    {0x6204, 0x01, 0xFF, 1},
    {0x6209, 0x00, 0xFF, 1},
    {0x621F, 0x01, 0xFF, 1},
    {0x621E, 0x10, 0xFF, 1},
    {0x48E3, 0x82, 0xFF, 1},
    {0x0114, 0x01, 0xFF, 1},
    {0x0340, 0x0A, 0xFF, 1},
    {0x0341, 0xD8, 0xFF, 1},
    {0x0342, 0x11, 0xFF, 1},
    {0x0343, 0x30, 0xFF, 1},
    {0x0344, 0x00, 0xFF, 1},
    {0x0345, 0x00, 0xFF, 1},
    {0x0346, 0x00, 0xFF, 1},
    {0x0347, 0x00, 0xFF, 1},
    {0x0348, 0x09, 0xFF, 1},
    {0x0349, 0x5F, 0xFF, 1},
    {0x034A, 0x0A, 0xFF, 1},
    {0x034B, 0x9F, 0xFF, 1},
    {0x0381, 0x01, 0xFF, 1},
    {0x0383, 0x01, 0xFF, 1},
    {0x0385, 0x01, 0xFF, 1},
    {0x0387, 0x01, 0xFF, 1},
    {0x0900, 0x00, 0xFF, 1},
    {0x0901, 0x00, 0xFF, 1},
    {0x0112, 0x0A, 0xFF, 1},
    {0x0113, 0x0A, 0xFF, 1},
    {0x034C, 0x09, 0xFF, 1},
    {0x034D, 0x60, 0xFF, 1},
    {0x034E, 0x0A, 0xFF, 1},
    {0x034F, 0xA0, 0xFF, 1},
    {0x0408, 0x00, 0xFF, 1},
    {0x0409, 0x00, 0xFF, 1},
    {0x040A, 0x00, 0xFF, 1},
    {0x040B, 0x00, 0xFF, 1},
    {0x040C, 0x09, 0xFF, 1},
    {0x040D, 0x60, 0xFF, 1},
    {0x040E, 0x0A, 0xFF, 1},
    {0x040F, 0xA0, 0xFF, 1},
    {0x0301, 0x07, 0xFF, 1},
    {0x0303, 0x02, 0xFF, 1},
    {0x0305, 0x04, 0xFF, 1},
    {0x0306, 0x00, 0xFF, 1},
    {0x0307, 0xC8, 0xFF, 1},
    {0x0309, 0x0A, 0xFF, 1},
    {0x030B, 0x01, 0xFF, 1},
    {0x030D, 0x0C, 0xFF, 1}, // Update for 996 mbps
    {0x030E, 0x01, 0xFF, 1}, // Update for 996 mbps
    {0x030F, 0xF2, 0xFF, 1}, // Update for 996 mbps
    {0x0310, 0x01, 0xFF, 1},
    {0x0820, 0x07, 0xFF, 1},
    {0x0821, 0xD0, 0xFF, 1},
    {0x0822, 0x00, 0xFF, 1},
    {0x0823, 0x00, 0xFF, 1},
    {0x3000, 0x00, 0xFF, 1},
    {0x3002, 0x01, 0xFF, 1},
    {0x3003, 0x20, 0xFF, 1},
    {0x6259, 0x03, 0xFF, 1},
    {0x0202, 0x0A, 0xFF, 1}, // int time
    {0x0203, 0xDE, 0xFF, 1},
    {0x0204, 0x00, 0xFF, 1},
    {0x0205, 0xC0, 0xFF, 1}, // a gain
    {0x020E, 0x01, 0xFF, 1},
    {0x020F, 0x00, 0xFF, 1},
    {0x0000, 0x0000, 0x0000, 0x0000},
};

// -----------------------//
//      SUPPORTED MODES
// -----------------------//

const init_seq_fmt_t* kSEQUENCE_TABLE[] = {
    setting_2200_2720_2lane_996mbps_30fps,
    setting_2200_2720_2lane_996mbps_30fps_test_pattern,
    setting_2200_2720_2lane_960m_30fps_test_pattern,
    setting_1920_1080_2lane_996mbps_30fps_test_pattern,
    setting_1920_1080_2lane_996mbps_30fps,
    setting_2400_2720_2lane_996mbps_28fps,
};

constexpr sensor_mode_t supported_modes[] = {
    {
        // NOTE: SW reference consumes this as (30fps * 256)
        //       We are representing this as fpms.
        //       Take account of the multiplier when needed.
        .fpms = 30000,
        .resolution = {
            .width = 2200,
            .height = 2720,
        },
        .exposures = 1,
        .wdr_mode = WDR_MODE_LINEAR,
        .bits = 10,
        .lanes = 2,
        .mbps = 1000,
        .idx = kSENSOR_IMX227_SEQUENCE_DEFAULT_PREVIEW,
        .bayer = BAYER_RGGB,
    },
    {
        // NOTE: SW reference consumes this as (30fps * 256)
        //       We are representing this as fpms.
        //       Take account of the multiplier when needed.
        .fpms = 30000,
        .resolution = {
            .width = 1920,
            .height = 1080,
        },
        .exposures = 1,
        .wdr_mode = WDR_MODE_LINEAR,
        .bits = 10,
        .lanes = 2,
        .mbps = 1000,
        .idx = kSENSOR_IMX227_SEQUENCE_1080P_PREVIEW,
        .bayer = BAYER_RGGB,
    },
    {
        // NOTE: SW reference consumes this as (28fps * 256)
        //       We are representing this as fpms.
        //       Take account of the multiplier when needed.
        .fpms = 28000,
        .resolution = {
            .width = 2400,
            .height = 2720,
        },
        .exposures = 1,
        .wdr_mode = WDR_MODE_LINEAR,
        .bits = 10,
        .lanes = 2,
        .mbps = 1000,
        .idx = kSENSOR_IMX227_SEQUENCE_DEFAULT_FULLSENSOR_PREVIEW,
        .bayer = BAYER_RGGB,
    },
};

} // namespace camera
