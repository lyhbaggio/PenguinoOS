use vars qw(%result_texis %result_texts %result_trees %result_errors 
   %result_indices %result_sectioning %result_nodes %result_menus
   %result_floats %result_converted %result_converted_errors 
   %result_elements %result_directions_text);

use utf8;

$result_trees{'macro_in_ifset_end_in_arg'} = {
  'contents' => [
    {
      'args' => [
        {
          'parent' => {},
          'text' => 'macroone',
          'type' => 'macro_name'
        },
        {
          'parent' => {},
          'text' => 'arg',
          'type' => 'macro_arg'
        }
      ],
      'cmdname' => 'macro',
      'contents' => [
        {
          'parent' => {},
          'text' => '@end ifset',
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
        'arg_line' => ' macroone {arg}
',
        'args_index' => {
          'arg' => 0
        },
        'macrobody' => '@end ifset
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
        'line_nr' => 1,
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
      'parent' => {},
      'text' => '
'
    },
    {
      'contents' => [
        {
          'parent' => {},
          'text' => 'in ifset
'
        },
        {
          'args' => [
            {
              'contents' => [
                {
                  'extra' => {
                    'command' => {}
                  },
                  'parent' => {},
                  'text' => ' ',
                  'type' => 'empty_spaces_after_command'
                },
                {
                  'parent' => {},
                  'text' => 'ifset'
                },
                {
                  'parent' => {},
                  'text' => '
',
                  'type' => 'spaces_at_end'
                }
              ],
              'parent' => {},
              'type' => 'misc_line_arg'
            }
          ],
          'cmdname' => 'end',
          'extra' => {
            'spaces_after_command' => {},
            'text_arg' => 'ifset'
          },
          'line_nr' => {
            'file_name' => '',
            'line_nr' => 10,
            'macro' => ''
          },
          'parent' => {}
        }
      ],
      'parent' => {},
      'type' => 'paragraph'
    }
  ],
  'type' => 'text_root'
};
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[0]{'args'}[0]{'parent'} = $result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[0];
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[0]{'args'}[1]{'parent'} = $result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[0];
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[0]{'contents'}[0]{'parent'} = $result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[0];
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[0]{'contents'}[1]{'parent'} = $result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[0];
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[0]{'extra'}{'spaces_after_command'}{'extra'}{'command'} = $result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[0];
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[0]{'extra'}{'spaces_after_command'}{'parent'} = $result_trees{'macro_in_ifset_end_in_arg'};
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[0]{'parent'} = $result_trees{'macro_in_ifset_end_in_arg'};
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[1] = $result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[0]{'extra'}{'spaces_after_command'};
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[2]{'parent'} = $result_trees{'macro_in_ifset_end_in_arg'};
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[3]{'parent'} = $result_trees{'macro_in_ifset_end_in_arg'};
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[4]{'contents'}[0]{'parent'} = $result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[4];
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[4]{'contents'}[1]{'args'}[0]{'contents'}[0]{'extra'}{'command'} = $result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[4]{'contents'}[1];
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[4]{'contents'}[1]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[4]{'contents'}[1]{'args'}[0];
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[4]{'contents'}[1]{'args'}[0]{'contents'}[1]{'parent'} = $result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[4]{'contents'}[1]{'args'}[0];
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[4]{'contents'}[1]{'args'}[0]{'contents'}[2]{'parent'} = $result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[4]{'contents'}[1]{'args'}[0];
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[4]{'contents'}[1]{'args'}[0]{'parent'} = $result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[4]{'contents'}[1];
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[4]{'contents'}[1]{'extra'}{'spaces_after_command'} = $result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[4]{'contents'}[1]{'args'}[0]{'contents'}[0];
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[4]{'contents'}[1]{'parent'} = $result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[4];
$result_trees{'macro_in_ifset_end_in_arg'}{'contents'}[4]{'parent'} = $result_trees{'macro_in_ifset_end_in_arg'};

$result_texis{'macro_in_ifset_end_in_arg'} = '@macro macroone {arg}
@end ifset
@end macro


in ifset
@end ifset
';


$result_texts{'macro_in_ifset_end_in_arg'} = '

in ifset
';

$result_errors{'macro_in_ifset_end_in_arg'} = [
  {
    'error_line' => ':8: Misplaced }
',
    'file_name' => '',
    'line_nr' => 8,
    'macro' => '',
    'text' => 'Misplaced }',
    'type' => 'error'
  },
  {
    'error_line' => ':10: Unmatched `@end\'
',
    'file_name' => '',
    'line_nr' => 10,
    'macro' => '',
    'text' => 'Unmatched `@end\'',
    'type' => 'error'
  }
];


1;
