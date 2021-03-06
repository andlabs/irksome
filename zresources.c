#include <gio/gio.h>

#if defined (__ELF__) && ( __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 6))
# define SECTION __attribute__ ((section (".gresource.gresources"), aligned (8)))
#else
# define SECTION
#endif

static const SECTION union { const guint8 data[2215]; const double alignment; void * const ptr;}  gresources_resource_data = { {
  0x47, 0x56, 0x61, 0x72, 0x69, 0x61, 0x6e, 0x74, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x18, 0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x28, 0x03, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x01, 0x00, 0x00, 0x00, 0x3d, 0x60, 0x5c, 0x85, 
  0x01, 0x00, 0x00, 0x00, 0x74, 0x00, 0x00, 0x00, 
  0x08, 0x00, 0x4c, 0x00, 0x7c, 0x00, 0x00, 0x00, 
  0x80, 0x00, 0x00, 0x00, 0xd4, 0xb5, 0x02, 0x00, 
  0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 
  0x01, 0x00, 0x4c, 0x00, 0x84, 0x00, 0x00, 0x00, 
  0x88, 0x00, 0x00, 0x00, 0xbc, 0xac, 0xd7, 0x66, 
  0x00, 0x00, 0x00, 0x00, 0x88, 0x00, 0x00, 0x00, 
  0x0a, 0x00, 0x76, 0x00, 0x98, 0x00, 0x00, 0x00, 
  0xa7, 0x08, 0x00, 0x00, 0x69, 0x72, 0x6b, 0x73, 
  0x6f, 0x6d, 0x65, 0x2f, 0x02, 0x00, 0x00, 0x00, 
  0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x6d, 0x61, 0x69, 0x6e, 0x77, 0x69, 0x6e, 0x2e, 
  0x75, 0x69, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0xa6, 0x2e, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 
  0x78, 0xda, 0xed, 0x5a, 0x5d, 0x6f, 0xdb, 0x36, 
  0x14, 0x7d, 0xef, 0xaf, 0xe0, 0xb8, 0x97, 0x16, 
  0x83, 0xfc, 0x95, 0x15, 0x2b, 0x06, 0xdb, 0x05, 
  0x56, 0xac, 0x59, 0x80, 0x60, 0x18, 0xd6, 0x6c, 
  0x7b, 0x14, 0x68, 0xea, 0xda, 0xe2, 0x4c, 0x93, 
  0x1a, 0x49, 0x3b, 0x56, 0x7f, 0xfd, 0x28, 0x29, 
  0x6e, 0x94, 0x98, 0xb2, 0x3e, 0xe3, 0xda, 0x4d, 
  0x9e, 0x22, 0x47, 0xbc, 0x14, 0xef, 0xe1, 0xe1, 
  0xb9, 0x87, 0xa2, 0xc6, 0xef, 0xb7, 0x2b, 0x8e, 
  0x36, 0xa0, 0x34, 0x93, 0x62, 0x82, 0x87, 0xbd, 
  0x01, 0x46, 0x20, 0xa8, 0x0c, 0x98, 0x58, 0x4c, 
  0xf0, 0x5f, 0x37, 0x1f, 0xbd, 0x77, 0xf8, 0xfd, 
  0xf4, 0xd5, 0xf8, 0x3b, 0xcf, 0x43, 0x97, 0x20, 
  0x40, 0x11, 0x03, 0x01, 0xba, 0x65, 0x26, 0x44, 
  0x0b, 0x4e, 0x02, 0x40, 0x17, 0xbd, 0xe1, 0xbb, 
  0xde, 0x05, 0xf2, 0x3c, 0xdb, 0x88, 0x09, 0x03, 
  0x6a, 0x4e, 0x28, 0x4c, 0x5f, 0x21, 0x34, 0x56, 
  0xf0, 0xdf, 0x9a, 0x29, 0xd0, 0x88, 0xb3, 0xd9, 
  0x04, 0x2f, 0xcc, 0xf2, 0x07, 0x7c, 0xff, 0x20, 
  0x1b, 0x36, 0xc2, 0xfd, 0xb4, 0x9d, 0x9c, 0xfd, 
  0x0b, 0xd4, 0x20, 0xca, 0x89, 0xd6, 0x13, 0x7c, 
  0x69, 0x96, 0xff, 0x30, 0x11, 0xc8, 0x5b, 0x8c, 
  0x58, 0x30, 0xc1, 0xb7, 0x4c, 0xe0, 0xa4, 0x95, 
  0x6d, 0x17, 0x29, 0x19, 0x81, 0x32, 0x31, 0x12, 
  0x64, 0x05, 0xc9, 0x9d, 0xc0, 0x84, 0x7e, 0xf2, 
  0x10, 0xd0, 0x06, 0x4f, 0x7f, 0x1a, 0x0c, 0xc6, 
  0xfd, 0x5d, 0x13, 0x77, 0x44, 0x08, 0x6c, 0x11, 
  0x9a, 0xfb, 0x90, 0xb7, 0xe5, 0x21, 0x94, 0x08, 
  0x7f, 0x2e, 0xe9, 0x5a, 0xe3, 0xe9, 0x47, 0xc2, 
  0x35, 0x94, 0xb5, 0x37, 0xcc, 0x70, 0xc0, 0xc8, 
  0x28, 0x22, 0x34, 0x27, 0x86, 0xcc, 0xb8, 0xfd, 
  0x67, 0x0c, 0x36, 0xfc, 0x4a, 0x2d, 0xb5, 0x5c, 
  0x95, 0x76, 0x60, 0xf1, 0x62, 0x9f, 0x93, 0xb0, 
  0x8a, 0x0f, 0x0c, 0x60, 0x4e, 0xd6, 0xdc, 0xf8, 
  0x29, 0x1a, 0x95, 0x50, 0xd8, 0x45, 0x64, 0x68, 
  0x54, 0x42, 0x21, 0x24, 0xda, 0x4f, 0x07, 0x06, 
  0xfe, 0x42, 0xb1, 0xa8, 0x68, 0x68, 0x34, 0x64, 
  0x3c, 0xc8, 0xae, 0x5d, 0xd3, 0xfa, 0x8b, 0xdc, 
  0x66, 0x73, 0x3a, 0x93, 0xdb, 0x21, 0xde, 0xb5, 
  0xdb, 0x7f, 0xda, 0x86, 0x69, 0x96, 0x02, 0x70, 
  0xa3, 0xd6, 0x7b, 0x0f, 0x69, 0x32, 0x49, 0xae, 
  0x18, 0xa9, 0x18, 0x08, 0x43, 0x8c, 0x25, 0x23, 
  0x9e, 0x5a, 0x56, 0x1a, 0x46, 0x09, 0x77, 0x06, 
  0x3e, 0xc8, 0xca, 0x9d, 0xd9, 0x1f, 0x44, 0x40, 
  0x90, 0xe5, 0x16, 0x25, 0x97, 0xf9, 0xec, 0x1a, 
  0x65, 0x58, 0x92, 0x65, 0x9d, 0xb0, 0x10, 0xb6, 
  0x76, 0x4c, 0x41, 0xbd, 0xa0, 0x4d, 0xa5, 0xa0, 
  0x3d, 0x64, 0xdc, 0xe8, 0x7c, 0xa2, 0x4a, 0x72, 
  0x0e, 0x41, 0x7e, 0x59, 0xd3, 0x90, 0x08, 0xce, 
  0xb4, 0xb9, 0xbb, 0xa7, 0xf0, 0xe3, 0x6e, 0x1a, 
  0x82, 0xd6, 0x02, 0x38, 0x27, 0x78, 0x3a, 0x1d, 
  0xdf, 0x8c, 0x28, 0x3f, 0x92, 0x9c, 0xd1, 0x18, 
  0x4f, 0x05, 0x58, 0xb6, 0xd4, 0xe9, 0x43, 0x87, 
  0xc4, 0xa6, 0xed, 0x9b, 0x38, 0xb2, 0x63, 0x67, 
  0xe2, 0x60, 0xa8, 0x13, 0x51, 0x37, 0xaa, 0x37, 
  0x0a, 0xe0, 0x6f, 0x06, 0x8f, 0xf0, 0xc4, 0xae, 
  0xe0, 0x16, 0x58, 0xb6, 0xc4, 0xd3, 0x4d, 0x48, 
  0x5b, 0x36, 0x94, 0xf6, 0xbf, 0x8c, 0xa1, 0x70, 
  0xcd, 0x1e, 0xea, 0x05, 0x44, 0x22, 0x92, 0xbe, 
  0x06, 0xa2, 0x68, 0xd8, 0xb0, 0x0f, 0x1d, 0xda, 
  0x79, 0xc9, 0x98, 0x6e, 0x07, 0xd4, 0x6e, 0x20, 
  0xc6, 0x4e, 0x87, 0xcf, 0x99, 0x80, 0x86, 0xa8, 
  0x10, 0x6a, 0xd8, 0xc6, 0xd6, 0x56, 0x5f, 0x0a, 
  0x5f, 0xdb, 0xda, 0x6b, 0xbb, 0xa4, 0x96, 0x70, 
  0xcb, 0x8a, 0xbd, 0xa5, 0xc4, 0x41, 0x69, 0xfd, 
  0x15, 0x84, 0x7b, 0xe9, 0x4f, 0x9b, 0x20, 0x70, 
  0x4b, 0x9a, 0x54, 0xe2, 0x9c, 0x61, 0x45, 0xbc, 
  0xfa, 0xf4, 0x25, 0x2e, 0x25, 0x57, 0xd6, 0x0d, 
  0x04, 0x1f, 0x2c, 0xc9, 0x04, 0xf0, 0xac, 0x6c, 
  0x3b, 0xfa, 0xea, 0x17, 0xd3, 0xb7, 0x9f, 0x3d, 
  0xc7, 0x41, 0x79, 0x77, 0x50, 0x51, 0xc0, 0x38, 
  0x22, 0x74, 0x69, 0xe1, 0x29, 0x5f, 0x76, 0x59, 
  0xbd, 0xaa, 0x30, 0xa9, 0xfb, 0xac, 0x50, 0x4c, 
  0x94, 0xe2, 0x6e, 0xef, 0xb8, 0x46, 0xe2, 0x4c, 
  0xa7, 0xaa, 0x50, 0xe6, 0x0b, 0xe4, 0xe8, 0x48, 
  0x8a, 0x58, 0x1b, 0x9e, 0xca, 0x85, 0xb3, 0x89, 
  0xa8, 0x5d, 0x93, 0x99, 0xe5, 0x57, 0x8a, 0x81, 
  0x91, 0x11, 0xa3, 0xd9, 0xef, 0xe3, 0x6a, 0x5a, 
  0x23, 0x15, 0x08, 0x09, 0x67, 0x0b, 0x0b, 0x88, 
  0x36, 0x44, 0x99, 0xfa, 0x8a, 0x58, 0xa1, 0xda, 
  0x16, 0x05, 0xf3, 0x0c, 0x32, 0x87, 0xe3, 0xbc, 
  0x5b, 0xae, 0xe8, 0x26, 0x41, 0x12, 0x5d, 0x4a, 
  0xeb, 0xc4, 0x7f, 0x03, 0x55, 0x5f, 0x25, 0xd3, 
  0xd5, 0x4f, 0x2a, 0x42, 0x5b, 0xbc, 0xd2, 0x0f, 
  0x2d, 0x5e, 0xa7, 0xb0, 0xde, 0x81, 0xd2, 0x68, 
  0x3e, 0xe6, 0x8c, 0xf3, 0x66, 0x78, 0x46, 0x52, 
  0xb3, 0x8c, 0xdc, 0x83, 0xb2, 0x4c, 0x8b, 0xb5, 
  0xa8, 0x48, 0x09, 0xeb, 0xac, 0x85, 0xc7, 0xa6, 
  0x72, 0x74, 0x16, 0xb5, 0xbd, 0x05, 0x93, 0x37, 
  0xb5, 0x82, 0x0b, 0x91, 0xac, 0x65, 0x42, 0x0f, 
  0x19, 0xd0, 0x4e, 0x00, 0xee, 0x00, 0xe4, 0xae, 
  0x8c, 0x69, 0x07, 0x06, 0xb5, 0x1a, 0xfa, 0x05, 
  0xc6, 0x02, 0xb6, 0xe6, 0x81, 0x61, 0x35, 0xf8, 
  0x50, 0x07, 0x1d, 0xe0, 0xde, 0x11, 0xf6, 0x4e, 
  0x71, 0x0a, 0x98, 0x21, 0xd5, 0xdd, 0x6b, 0xe1, 
  0x68, 0xd6, 0x4a, 0x4b, 0x55, 0xd3, 0x0a, 0x97, 
  0x0b, 0x6d, 0xa9, 0x1f, 0xab, 0xd2, 0xc1, 0x61, 
  0xb5, 0x6e, 0x65, 0xb9, 0xda, 0x59, 0xaf, 0x0a, 
  0x02, 0x5c, 0x9a, 0x7e, 0x17, 0xf2, 0x21, 0xac, 
  0x3d, 0x2f, 0xd9, 0xc3, 0xbe, 0x48, 0x48, 0xb7, 
  0x12, 0xf2, 0x60, 0xcf, 0xbb, 0xc3, 0xff, 0x9c, 
  0x64, 0xa4, 0xe9, 0x3e, 0xad, 0xd1, 0x7e, 0xed, 
  0x77, 0x0b, 0xd0, 0xb5, 0x05, 0x28, 0xf9, 0x5b, 
  0xb4, 0x69, 0xab, 0x28, 0x16, 0x27, 0xae, 0x38, 
  0x4d, 0xd7, 0xc0, 0xb1, 0x04, 0xe7, 0x1b, 0x72, 
  0xc5, 0xc3, 0xaf, 0xeb, 0x8a, 0xf3, 0x7b, 0xe4, 
  0x8b, 0xb3, 0xd8, 0x19, 0x3e, 0xa5, 0xab, 0xfd, 
  0x20, 0x57, 0x33, 0x69, 0x21, 0x49, 0xbc, 0x55, 
  0x06, 0xcb, 0x2a, 0x16, 0xe9, 0x5b, 0xa3, 0xaf, 
  0x52, 0x8a, 0x2a, 0x16, 0xfe, 0xee, 0x75, 0xa0, 
  0xd6, 0xaa, 0x68, 0xb7, 0x32, 0x5a, 0xed, 0x19, 
  0x8f, 0x6d, 0x5b, 0x72, 0xef, 0x53, 0xc8, 0x2d, 
  0x89, 0x0f, 0xbd, 0x4e, 0x39, 0x11, 0x6e, 0xd4, 
  0x79, 0xc1, 0xf1, 0x3a, 0xc9, 0xe9, 0xcd, 0xb3, 
  0xe6, 0xdb, 0xf0, 0xb4, 0xf8, 0xf6, 0xab, 0x30, 
  0x2a, 0xce, 0xf8, 0x96, 0xbc, 0x0b, 0x3f, 0x37, 
  0x47, 0x5c, 0x47, 0xaa, 0xbf, 0x69, 0x5a, 0x8d, 
  0x5e, 0xcc, 0x50, 0x17, 0x38, 0xd5, 0x37, 0x43, 
  0xdd, 0x9d, 0x7b, 0xd4, 0x3d, 0x13, 0xe8, 0xfa, 
  0xd8, 0xc3, 0x95, 0x89, 0x3b, 0x8b, 0x46, 0xb3, 
  0x5a, 0x7f, 0x36, 0x6b, 0x17, 0x6d, 0x47, 0xae, 
  0x7b, 0x79, 0x56, 0xf9, 0x3a, 0x20, 0x6f, 0x59, 
  0x7f, 0x7c, 0xe2, 0x2f, 0x03, 0x6a, 0x61, 0x16, 
  0x76, 0x79, 0xca, 0x9f, 0xcf, 0xf2, 0xed, 0xa9, 
  0x1e, 0x5e, 0x55, 0x56, 0xf8, 0x86, 0x87, 0x56, 
  0xda, 0x10, 0xb3, 0xd6, 0x2f, 0xa7, 0x56, 0x2d, 
  0x4c, 0xdd, 0x9f, 0x40, 0x82, 0xb8, 0xf7, 0x72, 
  0xc8, 0x74, 0x9c, 0xed, 0x74, 0x8e, 0xbb, 0x4c, 
  0xcc, 0xe5, 0xd9, 0x31, 0x17, 0x44, 0xd0, 0x1d, 
  0xf5, 0xbe, 0xa7, 0x77, 0x27, 0xa6, 0x1e, 0x1a, 
  0x0d, 0x06, 0x28, 0xd9, 0x48, 0x6b, 0xf4, 0x7a, 
  0x34, 0x40, 0x32, 0xd2, 0x6f, 0x10, 0x62, 0x8a, 
  0xf6, 0x34, 0xa8, 0x0d, 0xa8, 0x9e, 0x00, 0x63, 
  0x1b, 0x5d, 0x93, 0xc5, 0xcf, 0x68, 0x38, 0x18, 
  0xac, 0xf4, 0xb3, 0xa1, 0xeb, 0xf0, 0xf4, 0x0c, 
  0x4f, 0x65, 0x4c, 0x9a, 0xe1, 0xd1, 0x68, 0xe9, 
  0x3e, 0xc5, 0xd7, 0x21, 0x57, 0x2b, 0xb2, 0x80, 
  0xdd, 0x0b, 0x5e, 0xba, 0x56, 0x70, 0x45, 0x9d, 
  0x2f, 0x8c, 0x4f, 0xa2, 0xd0, 0x32, 0x3b, 0x36, 
  0x3f, 0xb9, 0xb4, 0xc5, 0x25, 0x19, 0x2c, 0x33, 
  0xb1, 0x17, 0xb2, 0x45, 0xe8, 0xe9, 0x78, 0x35, 
  0x4b, 0x4e, 0x1b, 0x0e, 0x61, 0x77, 0xb6, 0x8c, 
  0x18, 0x3e, 0x33, 0xe3, 0x3c, 0x6c, 0x6a, 0x9c, 
  0x1f, 0xe6, 0x98, 0xbb, 0x79, 0x7f, 0x63, 0xdc, 
  0xcf, 0x7d, 0x4d, 0xfe, 0x3f, 0x67, 0x3e, 0xa7, 
  0x6e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x28, 0x75, 0x75, 0x61, 0x79, 0x29
} };

static GStaticResource static_resource = { gresources_resource_data.data, sizeof (gresources_resource_data.data), NULL, NULL, NULL };
extern GResource *gresources_get_resource (void);
GResource *gresources_get_resource (void)
{
  return g_static_resource_get_resource (&static_resource);
}
/*
  If G_HAS_CONSTRUCTORS is true then the compiler support *both* constructors and
  destructors, in a sane way, including e.g. on library unload. If not you're on
  your own.

  Some compilers need #pragma to handle this, which does not work with macros,
  so the way you need to use this is (for constructors):

  #ifdef G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA
  #pragma G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(my_constructor)
  #endif
  G_DEFINE_CONSTRUCTOR(my_constructor)
  static void my_constructor(void) {
   ...
  }

*/

#if  __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 7)

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR(_func) static void __attribute__((constructor)) _func (void);
#define G_DEFINE_DESTRUCTOR(_func) static void __attribute__((destructor)) _func (void);

#elif defined (_MSC_VER) && (_MSC_VER >= 1500)
/* Visual studio 2008 and later has _Pragma */

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR(_func) \
  static void _func(void); \
  static int _func ## _wrapper(void) { _func(); return 0; } \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) static int (* _array ## _func)(void) = _func ## _wrapper;

#define G_DEFINE_DESTRUCTOR(_func) \
  static void _func(void); \
  static int _func ## _constructor(void) { atexit (_func); return 0; } \
  __pragma(section(".CRT$XCU",read)) \
  __declspec(allocate(".CRT$XCU")) static int (* _array ## _func)(void) = _func ## _constructor;

#elif defined (_MSC_VER)

#define G_HAS_CONSTRUCTORS 1

/* Pre Visual studio 2008 must use #pragma section */
#define G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA 1
#define G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA 1

#define G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(_func) \
  section(".CRT$XCU",read)
#define G_DEFINE_CONSTRUCTOR(_func) \
  static void _func(void); \
  static int _func ## _wrapper(void) { _func(); return 0; } \
  __declspec(allocate(".CRT$XCU")) static int (*p)(void) = _func ## _wrapper;

#define G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(_func) \
  section(".CRT$XCU",read)
#define G_DEFINE_DESTRUCTOR(_func) \
  static void _func(void); \
  static int _func ## _constructor(void) { atexit (_func); return 0; } \
  __declspec(allocate(".CRT$XCU")) static int (* _array ## _func)(void) = _func ## _constructor;

#elif defined(__SUNPRO_C)

/* This is not tested, but i believe it should work, based on:
 * http://opensource.apple.com/source/OpenSSL098/OpenSSL098-35/src/fips/fips_premain.c
 */

#define G_HAS_CONSTRUCTORS 1

#define G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA 1
#define G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA 1

#define G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(_func) \
  init(_func)
#define G_DEFINE_CONSTRUCTOR(_func) \
  static void _func(void);

#define G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(_func) \
  fini(_func)
#define G_DEFINE_DESTRUCTOR(_func) \
  static void _func(void);

#else

/* constructors not supported for this compiler */

#endif


#ifdef G_HAS_CONSTRUCTORS

#ifdef G_DEFINE_CONSTRUCTOR_NEEDS_PRAGMA
#pragma G_DEFINE_CONSTRUCTOR_PRAGMA_ARGS(resource_constructor)
#endif
G_DEFINE_CONSTRUCTOR(resource_constructor)
#ifdef G_DEFINE_DESTRUCTOR_NEEDS_PRAGMA
#pragma G_DEFINE_DESTRUCTOR_PRAGMA_ARGS(resource_destructor)
#endif
G_DEFINE_DESTRUCTOR(resource_destructor)

#else
#warning "Constructor not supported on this compiler, linking in resources will not work"
#endif

static void resource_constructor (void)
{
  g_static_resource_init (&static_resource);
}

static void resource_destructor (void)
{
  g_static_resource_fini (&static_resource);
}
