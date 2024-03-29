use strict;

use Test::More;
BEGIN { plan tests => 2 };

use lib 'maintain/lib/Unicode-EastAsianWidth/lib/';
use lib 'maintain/lib/libintl-perl/lib/';
use lib 'maintain/lib/Text-Unidecode/lib/';
use Texinfo::Parser qw(parse_texi_text);
use Texinfo::Structuring;
use Texinfo::Convert::Texinfo;

ok(1);

sub run_test($$$)
{
  my $in = shift;
  my $out = shift;
  my $name = shift;

  my $parser = Texinfo::Parser::parser();
  my $tree = parse_texi_text($parser, $in);

  my $corrected_tree 
    = Texinfo::Structuring::reference_to_arg_in_tree($parser, $tree);
  my $texi_result = Texinfo::Convert::Texinfo::convert($corrected_tree);

  if (!defined($out)) {
    print STDERR " --> $name:\n$texi_result";
  } else {
    is ($texi_result, $out, $name);
  }
}

run_test('AA @ref{a, b, c, d, e} (@pxref{,,, @code{trc}})',
'AA a (@code{trc})', 'simple test');
