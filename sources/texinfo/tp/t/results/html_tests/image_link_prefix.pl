use vars qw(%result_texis %result_texts %result_trees %result_errors 
   %result_indices %result_sectioning %result_nodes %result_menus
   %result_floats %result_converted %result_converted_errors 
   %result_elements %result_directions_text);

use utf8;

$result_trees{'image_link_prefix'} = {
  'contents' => [
    {
      'args' => [
        {
          'contents' => [
            {
              'parent' => {},
              'text' => 'image'
            }
          ],
          'parent' => {},
          'type' => 'brace_command_arg'
        }
      ],
      'cmdname' => 'image',
      'contents' => [],
      'extra' => {
        'brace_command_contents' => [
          [
            {}
          ]
        ],
        'spaces_before_argument' => {
          'text' => '',
          'type' => 'empty_spaces_before_argument'
        }
      },
      'line_nr' => {
        'file_name' => '',
        'line_nr' => 1,
        'macro' => ''
      },
      'parent' => {}
    }
  ],
  'type' => 'text_root'
};
$result_trees{'image_link_prefix'}{'contents'}[0]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'image_link_prefix'}{'contents'}[0]{'args'}[0];
$result_trees{'image_link_prefix'}{'contents'}[0]{'args'}[0]{'parent'} = $result_trees{'image_link_prefix'}{'contents'}[0];
$result_trees{'image_link_prefix'}{'contents'}[0]{'extra'}{'brace_command_contents'}[0][0] = $result_trees{'image_link_prefix'}{'contents'}[0]{'args'}[0]{'contents'}[0];
$result_trees{'image_link_prefix'}{'contents'}[0]{'parent'} = $result_trees{'image_link_prefix'};

$result_texis{'image_link_prefix'} = '@image{image}';


$result_texts{'image_link_prefix'} = 'image';

$result_errors{'image_link_prefix'} = [];



$result_converted{'html'}->{'image_link_prefix'} = '<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<!-- Created by texinfo, http://www.gnu.org/software/texinfo/ -->
<head>
<title>Untitled Document</title>

<meta name="description" content="Untitled Document">
<meta name="keywords" content="Untitled Document">
<meta name="resource-type" content="document">
<meta name="distribution" content="global">
<meta name="Generator" content="tp">
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<style type="text/css">
<!--
a.summary-letter {text-decoration: none}
blockquote.smallquotation {font-size: smaller}
div.display {margin-left: 3.2em}
div.example {margin-left: 3.2em}
div.indentedblock {margin-left: 3.2em}
div.lisp {margin-left: 3.2em}
div.smalldisplay {margin-left: 3.2em}
div.smallexample {margin-left: 3.2em}
div.smallindentedblock {margin-left: 3.2em; font-size: smaller}
div.smalllisp {margin-left: 3.2em}
kbd {font-style:oblique}
pre.display {font-family: inherit}
pre.format {font-family: inherit}
pre.menu-comment {font-family: serif}
pre.menu-preformatted {font-family: serif}
pre.smalldisplay {font-family: inherit; font-size: smaller}
pre.smallexample {font-size: smaller}
pre.smallformat {font-family: inherit; font-size: smaller}
pre.smalllisp {font-size: smaller}
span.nocodebreak {white-space:nowrap}
span.nolinebreak {white-space:nowrap}
span.roman {font-family:serif; font-weight:normal}
span.sansserif {font-family:sans-serif; font-weight:normal}
ul.no-bullet {list-style: none}
-->
</style>


</head>

<body lang="en" bgcolor="#FFFFFF" text="#000000" link="#0000FF" vlink="#800080" alink="#FF0000">
<img src="../imgimage.jpg" alt="image">


</body>
</html>
';

$result_converted_errors{'html'}->{'image_link_prefix'} = [
  {
    'error_line' => 'warning: Must specify a title with a title command or @top
',
    'text' => 'Must specify a title with a title command or @top',
    'type' => 'warning'
  },
  {
    'file_name' => '',
    'error_line' => ':1: warning: @image file `image\' (for HTML) not found, using `image.jpg\'
',
    'text' => '@image file `image\' (for HTML) not found, using `image.jpg\'',
    'type' => 'warning',
    'macro' => '',
    'line_nr' => 1
  }
];


1;
