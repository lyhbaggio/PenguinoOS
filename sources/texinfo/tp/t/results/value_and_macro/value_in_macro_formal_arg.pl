use vars qw(%result_texis %result_texts %result_trees %result_errors 
   %result_indices %result_sectioning %result_nodes %result_menus
   %result_floats %result_converted %result_converted_errors 
   %result_elements %result_directions_text);

use utf8;

$result_trees{'value_in_macro_formal_arg'} = {
  'contents' => [
    {
      'args' => [
        {
          'parent' => {},
          'text' => 'argument',
          'type' => 'misc_arg'
        },
        {
          'parent' => {},
          'text' => 'arg',
          'type' => 'misc_arg'
        }
      ],
      'cmdname' => 'set',
      'extra' => {
        'arg_line' => ' argument arg 
'
      },
      'parent' => {}
    },
    {
      'parent' => {},
      'text' => '
',
      'type' => 'empty_line'
    },
    {
      'args' => [
        {
          'parent' => {},
          'text' => 'testvalue',
          'type' => 'macro_name'
        },
        {
          'parent' => {},
          'text' => 'arg',
          'type' => 'macro_arg'
        },
        {
          'parent' => {},
          'text' => 'the@value{argument',
          'type' => 'macro_arg'
        }
      ],
      'cmdname' => 'macro',
      'contents' => [
        {
          'parent' => {},
          'text' => 'result: @emph{\\arg\\} the \\the\\ thearg \\thearg\\ with value \\the@value{argument}\\',
          'type' => 'raw'
        },
        {
          'parent' => {},
          'text' => '
',
          'type' => 'last_raw_newline'
        }
      ],
      'extra' => {
        'arg_line' => ' testvalue { arg , the@value{argument} }
',
        'args_index' => {
          'arg' => 0,
          'the@value{argument' => 1
        },
        'invalid_syntax' => 1,
        'macrobody' => 'result: @emph{\\arg\\} the \\the\\ thearg \\thearg\\ with value \\the@value{argument}\\
',
        'spaces_after_command' => {
          'extra' => {
            'command' => {}
          },
          'parent' => {},
          'text' => '
',
          'type' => 'empty_line_after_command'
        }
      },
      'line_nr' => {
        'file_name' => '',
        'line_nr' => 3,
        'macro' => ''
      },
      'parent' => {}
    },
    {},
    {
      'parent' => {},
      'text' => '
',
      'type' => 'empty_line'
    },
    {
      'contents' => [
        {
          'parent' => {},
          'text' => 'macro_arg1
'
        }
      ],
      'parent' => {},
      'type' => 'paragraph'
    }
  ],
  'type' => 'text_root'
};
$result_trees{'value_in_macro_formal_arg'}{'contents'}[0]{'args'}[0]{'parent'} = $result_trees{'value_in_macro_formal_arg'}{'contents'}[0];
$result_trees{'value_in_macro_formal_arg'}{'contents'}[0]{'args'}[1]{'parent'} = $result_trees{'value_in_macro_formal_arg'}{'contents'}[0];
$result_trees{'value_in_macro_formal_arg'}{'contents'}[0]{'parent'} = $result_trees{'value_in_macro_formal_arg'};
$result_trees{'value_in_macro_formal_arg'}{'contents'}[1]{'parent'} = $result_trees{'value_in_macro_formal_arg'};
$result_trees{'value_in_macro_formal_arg'}{'contents'}[2]{'args'}[0]{'parent'} = $result_trees{'value_in_macro_formal_arg'}{'contents'}[2];
$result_trees{'value_in_macro_formal_arg'}{'contents'}[2]{'args'}[1]{'parent'} = $result_trees{'value_in_macro_formal_arg'}{'contents'}[2];
$result_trees{'value_in_macro_formal_arg'}{'contents'}[2]{'args'}[2]{'parent'} = $result_trees{'value_in_macro_formal_arg'}{'contents'}[2];
$result_trees{'value_in_macro_formal_arg'}{'contents'}[2]{'contents'}[0]{'parent'} = $result_trees{'value_in_macro_formal_arg'}{'contents'}[2];
$result_trees{'value_in_macro_formal_arg'}{'contents'}[2]{'contents'}[1]{'parent'} = $result_trees{'value_in_macro_formal_arg'}{'contents'}[2];
$result_trees{'value_in_macro_formal_arg'}{'contents'}[2]{'extra'}{'spaces_after_command'}{'extra'}{'command'} = $result_trees{'value_in_macro_formal_arg'}{'contents'}[2];
$result_trees{'value_in_macro_formal_arg'}{'contents'}[2]{'extra'}{'spaces_after_command'}{'parent'} = $result_trees{'value_in_macro_formal_arg'};
$result_trees{'value_in_macro_formal_arg'}{'contents'}[2]{'parent'} = $result_trees{'value_in_macro_formal_arg'};
$result_trees{'value_in_macro_formal_arg'}{'contents'}[3] = $result_trees{'value_in_macro_formal_arg'}{'contents'}[2]{'extra'}{'spaces_after_command'};
$result_trees{'value_in_macro_formal_arg'}{'contents'}[4]{'parent'} = $result_trees{'value_in_macro_formal_arg'};
$result_trees{'value_in_macro_formal_arg'}{'contents'}[5]{'contents'}[0]{'parent'} = $result_trees{'value_in_macro_formal_arg'}{'contents'}[5];
$result_trees{'value_in_macro_formal_arg'}{'contents'}[5]{'parent'} = $result_trees{'value_in_macro_formal_arg'};

$result_texis{'value_in_macro_formal_arg'} = '@set argument arg 

@macro testvalue { arg , the@value{argument} }
result: @emph{\\arg\\} the \\the\\ thearg \\thearg\\ with value \\the@value{argument}\\
@end macro

macro_arg1
';


$result_texts{'value_in_macro_formal_arg'} = '

macro_arg1
';

$result_errors{'value_in_macro_formal_arg'} = [
  {
    'error_line' => ':3: Bad syntax for @macro argument: }
',
    'file_name' => '',
    'line_nr' => 3,
    'macro' => '',
    'text' => 'Bad syntax for @macro argument: }',
    'type' => 'error'
  },
  {
    'error_line' => ':3: Bad or empty @macro formal argument: the@value{argument
',
    'file_name' => '',
    'line_nr' => 3,
    'macro' => '',
    'text' => 'Bad or empty @macro formal argument: the@value{argument',
    'type' => 'error'
  },
  {
    'error_line' => ':7: Unknown command `testvalue\'
',
    'file_name' => '',
    'line_nr' => 7,
    'macro' => '',
    'text' => 'Unknown command `testvalue\'',
    'type' => 'error'
  },
  {
    'error_line' => ':7: Misplaced {
',
    'file_name' => '',
    'line_nr' => 7,
    'macro' => '',
    'text' => 'Misplaced {',
    'type' => 'error'
  },
  {
    'error_line' => ':7: Misplaced }
',
    'file_name' => '',
    'line_nr' => 7,
    'macro' => '',
    'text' => 'Misplaced }',
    'type' => 'error'
  }
];


1;
