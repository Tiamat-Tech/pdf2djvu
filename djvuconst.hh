/* Copyright © 2007, 2008, 2009 Jakub Wilk
 *
 * This package is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 dated June, 1991.
 */

namespace djvu
{
  static const int min_dpi = 72;
  static const int max_dpi = 6000;
  /* ``djvumake`` used to require dpi ≥ 72.
   * The library itself enforces dpi ≤ 6000.
   *
   * See
   * <http://sf.net/tracker/?func=detail&aid=1956093&group_id=32953&atid=406583>
   * for details.
   */

  static const unsigned int max_fg_colors = 4080;

  static const unsigned int max_subsample_ratio = 12;

  static const unsigned int version = 1;

  static const char shared_ant_file_name[] = "shared_anno.iff";

  namespace binary 
  {

    static const char version = static_cast<char>(djvu::version);

    static const char djvm_head[] = "AT&TFORM\0\0\0\0DJVMDIRM\0\0\0";

    static const char dummy_head[12] = 
    { 0x41, 0x54, 0x26, 0x54, 0x46, 0x4f, 0x52, 0x4d,
      0x00, 0x00, 0x00, 0x20
    };

    static const char dummy_double_head[48] = 
    { 0x41, 0x54, 0x26, 0x54, 0x46, 0x4f, 0x52, 0x4d, 
      0x00, 0x00, 0x00, 0x74, 0x44, 0x4a, 0x56, 0x4d,
      0x44, 0x49, 0x52, 0x4d, 0x00, 0x00, 0x00, 0x18,
      0x81, 0x00, 0x02, 0x00, 0x00, 0x00, 0x30, 0x00,
      0x00, 0x00, 0x58, 0xff, 0xff, 0xf2, 0xbf, 0x34,
      0x7b, 0xf3, 0x10, 0x74, 0x07, 0x45, 0xc5, 0x40
    };

    static const char dummy_page_data[32] =
    { 0x44, 0x4a, 0x56, 0x55, 0x49, 0x4e, 0x46, 0x4f,
      0x00, 0x00, 0x00, 0x0a, 0x00, 0x01, 0x00, 0x01,
      0x18, 0x00, 0x2c, 0x01, 0x16, 0x00, 0x53, 0x6a,
      0x62, 0x7a, 0x00, 0x00, 0x00, 0x02, 0xbb, 0x7f
    };

  }

}

// vim:ts=2 sw=2 et
