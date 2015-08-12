# encoding=UTF-8

# Copyright © 2010-2015 Jakub Wilk <jwilk@jwilk.net>
#
# This file is part of pdfdjvu.
#
# pdf2djvu is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License version 2 as
# published by the Free Software Foundation.
#
# pdf2djvu is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# General Public License for more details.

from common import (
    assert_equal,
    case,
    count_ppm_colors,
)

class test(case):
    '''
    https://bitbucket.org/jwilk/pdf2djvu/issue/45
    fixed in [fc7df6c4d3d3]
    '''
    def test(self):
        yield self._test, 'default', 325
        yield self._test, 'web', 43
        yield self._test, 'black', 2

    def _test(self, method, n):
        self.pdf2djvu(
            '--dpi=72',
            '--fg-colors={method}'.format(method=method)
        ).assert_()
        r = self.decode()
        r.assert_(stdout=None)
        r = self.decode(mode='foreground')
        r.assert_(stdout=None)
        colors = count_ppm_colors(r.stdout)
        assert_equal(len(colors), n)

# vim:ts=4 sts=4 sw=4 et
