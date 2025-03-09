unsigned char program_wasm[] = {
  0x00, 0x61, 0x73, 0x6d, 0x01, 0x00, 0x00, 0x00, 0x01, 0x0b, 0x02, 0x60,
  0x03, 0x7f, 0x7f, 0x7f, 0x00, 0x60, 0x00, 0x01, 0x7f, 0x02, 0x0f, 0x01,
  0x03, 0x65, 0x6e, 0x76, 0x07, 0x70, 0x72, 0x69, 0x6e, 0x74, 0x78, 0x79,
  0x00, 0x00, 0x03, 0x02, 0x01, 0x01, 0x04, 0x05, 0x01, 0x70, 0x01, 0x01,
  0x01, 0x05, 0x03, 0x01, 0x00, 0x02, 0x06, 0x08, 0x01, 0x7f, 0x01, 0x41,
  0xa0, 0x88, 0x04, 0x0b, 0x07, 0x11, 0x02, 0x06, 0x6d, 0x65, 0x6d, 0x6f,
  0x72, 0x79, 0x02, 0x00, 0x04, 0x6d, 0x61, 0x69, 0x6e, 0x00, 0x01, 0x0a,
  0x5f, 0x01, 0x5d, 0x01, 0x09, 0x7f, 0x23, 0x80, 0x80, 0x80, 0x80, 0x00,
  0x21, 0x00, 0x41, 0x10, 0x21, 0x01, 0x20, 0x00, 0x20, 0x01, 0x6b, 0x21,
  0x02, 0x20, 0x02, 0x24, 0x80, 0x80, 0x80, 0x80, 0x00, 0x41, 0x00, 0x21,
  0x03, 0x20, 0x02, 0x20, 0x03, 0x36, 0x02, 0x0c, 0x41, 0x00, 0x21, 0x04,
  0x41, 0x80, 0x88, 0x80, 0x80, 0x00, 0x21, 0x05, 0x20, 0x04, 0x20, 0x04,
  0x20, 0x05, 0x10, 0x80, 0x80, 0x80, 0x80, 0x00, 0x41, 0xc5, 0x00, 0x21,
  0x06, 0x41, 0x10, 0x21, 0x07, 0x20, 0x02, 0x20, 0x07, 0x6a, 0x21, 0x08,
  0x20, 0x08, 0x24, 0x80, 0x80, 0x80, 0x80, 0x00, 0x20, 0x06, 0x0f, 0x0b,
  0x0b, 0x25, 0x01, 0x00, 0x41, 0x80, 0x08, 0x0b, 0x1e, 0x68, 0x65, 0x6c,
  0x6c, 0x6f, 0x20, 0x77, 0x6f, 0x72, 0x6c, 0x64, 0x20, 0x66, 0x72, 0x6f,
  0x6d, 0x20, 0x57, 0x65, 0x62, 0x41, 0x73, 0x73, 0x65, 0x6d, 0x62, 0x6c,
  0x79, 0x21, 0x00, 0x00, 0x51, 0x04, 0x6e, 0x61, 0x6d, 0x65, 0x00, 0x0d,
  0x0c, 0x70, 0x72, 0x6f, 0x67, 0x72, 0x61, 0x6d, 0x2e, 0x77, 0x61, 0x73,
  0x6d, 0x01, 0x1b, 0x02, 0x00, 0x07, 0x70, 0x72, 0x69, 0x6e, 0x74, 0x78,
  0x79, 0x01, 0x0f, 0x5f, 0x5f, 0x6f, 0x72, 0x69, 0x67, 0x69, 0x6e, 0x61,
  0x6c, 0x5f, 0x6d, 0x61, 0x69, 0x6e, 0x07, 0x12, 0x01, 0x00, 0x0f, 0x5f,
  0x5f, 0x73, 0x74, 0x61, 0x63, 0x6b, 0x5f, 0x70, 0x6f, 0x69, 0x6e, 0x74,
  0x65, 0x72, 0x09, 0x0a, 0x01, 0x00, 0x07, 0x2e, 0x72, 0x6f, 0x64, 0x61,
  0x74, 0x61, 0x00, 0x26, 0x09, 0x70, 0x72, 0x6f, 0x64, 0x75, 0x63, 0x65,
  0x72, 0x73, 0x01, 0x0c, 0x70, 0x72, 0x6f, 0x63, 0x65, 0x73, 0x73, 0x65,
  0x64, 0x2d, 0x62, 0x79, 0x01, 0x05, 0x63, 0x6c, 0x61, 0x6e, 0x67, 0x06,
  0x31, 0x39, 0x2e, 0x31, 0x2e, 0x37, 0x00, 0x49, 0x0f, 0x74, 0x61, 0x72,
  0x67, 0x65, 0x74, 0x5f, 0x66, 0x65, 0x61, 0x74, 0x75, 0x72, 0x65, 0x73,
  0x04, 0x2b, 0x0a, 0x6d, 0x75, 0x6c, 0x74, 0x69, 0x76, 0x61, 0x6c, 0x75,
  0x65, 0x2b, 0x0f, 0x6d, 0x75, 0x74, 0x61, 0x62, 0x6c, 0x65, 0x2d, 0x67,
  0x6c, 0x6f, 0x62, 0x61, 0x6c, 0x73, 0x2b, 0x0f, 0x72, 0x65, 0x66, 0x65,
  0x72, 0x65, 0x6e, 0x63, 0x65, 0x2d, 0x74, 0x79, 0x70, 0x65, 0x73, 0x2b,
  0x08, 0x73, 0x69, 0x67, 0x6e, 0x2d, 0x65, 0x78, 0x74
};
unsigned int program_wasm_len = 417;
