use vars qw(%result_texis %result_texts %result_trees %result_errors 
   %result_indices %result_sectioning %result_nodes %result_menus
   %result_floats %result_converted %result_converted_errors 
   %result_elements %result_directions_text);

use utf8;

$result_trees{'float_with_at_commands'} = {
  'contents' => [
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
              'text' => 'entr'
            },
            {
              'args' => [
                {
                  'contents' => [
                    {
                      'parent' => {},
                      'text' => 'e'
                    }
                  ],
                  'parent' => {},
                  'type' => 'following_arg'
                }
              ],
              'cmdname' => '\'',
              'parent' => {}
            },
            {
              'parent' => {},
              'text' => 'e'
            }
          ],
          'parent' => {},
          'type' => 'block_line_arg'
        },
        {
          'contents' => [
            {
              'text' => ' ',
              'type' => 'empty_spaces_before_argument'
            },
            {
              'parent' => {},
              'text' => 'premi'
            },
            {
              'args' => [
                {
                  'contents' => [
                    {
                      'parent' => {},
                      'text' => 'e'
                    }
                  ],
                  'parent' => {},
                  'type' => 'following_arg'
                }
              ],
              'cmdname' => '`',
              'parent' => {}
            },
            {
              'parent' => {},
              'text' => 're entr'
            },
            {
              'args' => [
                {
                  'contents' => [
                    {
                      'parent' => {},
                      'text' => 'e'
                    }
                  ],
                  'parent' => {},
                  'type' => 'following_arg'
                }
              ],
              'cmdname' => '\'',
              'parent' => {}
            },
            {
              'parent' => {},
              'text' => 'e'
            },
            {
              'parent' => {},
              'text' => '
',
              'type' => 'space_at_end_block_command'
            }
          ],
          'parent' => {},
          'type' => 'block_line_arg'
        }
      ],
      'cmdname' => 'float',
      'contents' => [
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
              'text' => 'Ceci est notre premi'
            },
            {
              'args' => [
                {
                  'contents' => [
                    {
                      'parent' => {},
                      'text' => 'e'
                    }
                  ],
                  'parent' => {},
                  'type' => 'following_arg'
                }
              ],
              'cmdname' => '`',
              'parent' => {}
            },
            {
              'parent' => {},
              'text' => 're entr'
            },
            {
              'args' => [
                {
                  'contents' => [
                    {
                      'parent' => {},
                      'text' => 'e'
                    }
                  ],
                  'parent' => {},
                  'type' => 'following_arg'
                }
              ],
              'cmdname' => '\'',
              'parent' => {}
            },
            {
              'parent' => {},
              'text' => 'e.
'
            }
          ],
          'parent' => {},
          'type' => 'paragraph'
        },
        {
          'args' => [
            {
              'contents' => [
                {
                  'contents' => [
                    {
                      'parent' => {},
                      'text' => 'La premi'
                    },
                    {
                      'args' => [
                        {
                          'contents' => [
                            {
                              'parent' => {},
                              'text' => 'e'
                            }
                          ],
                          'parent' => {},
                          'type' => 'following_arg'
                        }
                      ],
                      'cmdname' => '`',
                      'parent' => {}
                    },
                    {
                      'parent' => {},
                      'text' => 're entr'
                    },
                    {
                      'args' => [
                        {
                          'contents' => [
                            {
                              'parent' => {},
                              'text' => 'e'
                            }
                          ],
                          'parent' => {},
                          'type' => 'following_arg'
                        }
                      ],
                      'cmdname' => '\'',
                      'parent' => {}
                    },
                    {
                      'parent' => {},
                      'text' => 'e est importante'
                    }
                  ],
                  'parent' => {},
                  'type' => 'paragraph'
                }
              ],
              'parent' => {},
              'type' => 'brace_command_context'
            }
          ],
          'cmdname' => 'caption',
          'contents' => [],
          'extra' => {
            'float' => {},
            'spaces_before_argument' => {
              'parent' => {},
              'text' => '',
              'type' => 'empty_spaces_before_argument'
            }
          },
          'line_nr' => {
            'file_name' => '',
            'line_nr' => 4,
            'macro' => ''
          },
          'parent' => {}
        },
        {
          'parent' => {},
          'text' => '
'
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
                  'text' => 'float'
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
            'command' => {},
            'command_argument' => 'float',
            'spaces_after_command' => {},
            'text_arg' => 'float'
          },
          'line_nr' => {
            'file_name' => '',
            'line_nr' => 6,
            'macro' => ''
          },
          'parent' => {}
        }
      ],
      'extra' => {
        'block_command_line_contents' => [
          [
            {},
            {},
            {}
          ],
          [
            {},
            {},
            {},
            {},
            {}
          ]
        ],
        'caption' => {},
        'end_command' => {},
        'node_content' => [
          {},
          {},
          {},
          {},
          {}
        ],
        'normalized' => 'premi_00e8re-entr_00e9e',
        'spaces_after_command' => {},
        'type' => {
          'content' => [
            {},
            {},
            {}
          ],
          'normalized' => 'entr_00e9e'
        }
      },
      'line_nr' => {
        'file_name' => '',
        'line_nr' => 1,
        'macro' => ''
      },
      'number' => 1,
      'parent' => {}
    },
    {
      'parent' => {},
      'text' => '
',
      'type' => 'empty_line'
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
              'text' => 'entr'
            },
            {
              'args' => [
                {
                  'contents' => [
                    {
                      'parent' => {},
                      'text' => 'e'
                    }
                  ],
                  'parent' => {},
                  'type' => 'following_arg'
                }
              ],
              'cmdname' => '\'',
              'parent' => {}
            },
            {
              'parent' => {},
              'text' => 'e'
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
      'cmdname' => 'listoffloats',
      'extra' => {
        'spaces_after_command' => {},
        'type' => {
          'content' => [
            {},
            {},
            {}
          ],
          'normalized' => 'entr_00e9e'
        }
      },
      'line_nr' => {
        'file_name' => '',
        'line_nr' => 9,
        'macro' => ''
      },
      'parent' => {}
    }
  ],
  'type' => 'text_root'
};
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0]{'contents'}[0]{'extra'}{'command'} = $result_trees{'float_with_at_commands'}{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0]{'contents'}[1]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0]{'contents'}[2]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0]{'contents'}[2]{'args'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0]{'contents'}[2];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0]{'contents'}[2]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0]{'contents'}[3]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[1]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[2]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[2]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[2]{'args'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[2];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[2]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[3]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[4]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[4]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[4]{'args'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[4];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[4]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[5]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[6]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1]{'contents'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1]{'contents'}[1]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1]{'contents'}[1]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1]{'contents'}[1]{'args'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1]{'contents'}[1];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1]{'contents'}[1]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1]{'contents'}[2]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1]{'contents'}[3]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1]{'contents'}[3]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1]{'contents'}[3]{'args'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1]{'contents'}[3];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1]{'contents'}[3]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1]{'contents'}[4]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[1]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0]{'contents'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0]{'contents'}[1]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0]{'contents'}[1]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0]{'contents'}[1]{'args'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0]{'contents'}[1];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0]{'contents'}[1]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0]{'contents'}[2]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0]{'contents'}[3]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0]{'contents'}[3]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0]{'contents'}[3]{'args'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0]{'contents'}[3];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0]{'contents'}[3]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0]{'contents'}[4]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'extra'}{'float'} = $result_trees{'float_with_at_commands'}{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'extra'}{'spaces_before_argument'}{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[3]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[4]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[5]{'args'}[0]{'contents'}[0]{'extra'}{'command'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[5];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[5]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[5]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[5]{'args'}[0]{'contents'}[1]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[5]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[5]{'args'}[0]{'contents'}[2]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[5]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[5]{'args'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[5];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[5]{'extra'}{'command'} = $result_trees{'float_with_at_commands'}{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[5]{'extra'}{'spaces_after_command'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[5]{'args'}[0]{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[5]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'block_command_line_contents'}[0][0] = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0]{'contents'}[1];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'block_command_line_contents'}[0][1] = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0]{'contents'}[2];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'block_command_line_contents'}[0][2] = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0]{'contents'}[3];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'block_command_line_contents'}[1][0] = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[1];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'block_command_line_contents'}[1][1] = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[2];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'block_command_line_contents'}[1][2] = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[3];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'block_command_line_contents'}[1][3] = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[4];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'block_command_line_contents'}[1][4] = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[5];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'caption'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[2];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'end_command'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'contents'}[5];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'node_content'}[0] = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[1];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'node_content'}[1] = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[2];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'node_content'}[2] = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[3];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'node_content'}[3] = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[4];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'node_content'}[4] = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[1]{'contents'}[5];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'spaces_after_command'} = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0]{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'type'}{'content'}[0] = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0]{'contents'}[1];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'type'}{'content'}[1] = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0]{'contents'}[2];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'extra'}{'type'}{'content'}[2] = $result_trees{'float_with_at_commands'}{'contents'}[0]{'args'}[0]{'contents'}[3];
$result_trees{'float_with_at_commands'}{'contents'}[0]{'parent'} = $result_trees{'float_with_at_commands'};
$result_trees{'float_with_at_commands'}{'contents'}[1]{'parent'} = $result_trees{'float_with_at_commands'};
$result_trees{'float_with_at_commands'}{'contents'}[2]{'parent'} = $result_trees{'float_with_at_commands'};
$result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0]{'contents'}[0]{'extra'}{'command'} = $result_trees{'float_with_at_commands'}{'contents'}[3];
$result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0]{'contents'}[1]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0]{'contents'}[2]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0]{'contents'}[2]{'args'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0]{'contents'}[2];
$result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0]{'contents'}[2]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0]{'contents'}[3]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0]{'contents'}[4]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0]{'parent'} = $result_trees{'float_with_at_commands'}{'contents'}[3];
$result_trees{'float_with_at_commands'}{'contents'}[3]{'extra'}{'spaces_after_command'} = $result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0]{'contents'}[0];
$result_trees{'float_with_at_commands'}{'contents'}[3]{'extra'}{'type'}{'content'}[0] = $result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0]{'contents'}[1];
$result_trees{'float_with_at_commands'}{'contents'}[3]{'extra'}{'type'}{'content'}[1] = $result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0]{'contents'}[2];
$result_trees{'float_with_at_commands'}{'contents'}[3]{'extra'}{'type'}{'content'}[2] = $result_trees{'float_with_at_commands'}{'contents'}[3]{'args'}[0]{'contents'}[3];
$result_trees{'float_with_at_commands'}{'contents'}[3]{'parent'} = $result_trees{'float_with_at_commands'};

$result_texis{'float_with_at_commands'} = '@float entr@\'ee, premi@`ere entr@\'ee

Ceci est notre premi@`ere entr@\'ee.
@caption{La premi@`ere entr@\'ee est importante}

@end float


@listoffloats entr@\'ee
';


$result_texts{'float_with_at_commands'} = 'entre\'e, premie`re entre\'e

Ceci est notre premie`re entre\'e.




';

$result_errors{'float_with_at_commands'} = [];


$result_floats{'float_with_at_commands'} = {
  'entr_00e9e' => [
    {
      'cmdname' => 'float',
      'extra' => {
        'caption' => {
          'cmdname' => 'caption',
          'extra' => {
            'float' => {},
            'spaces_before_argument' => {
              'text' => '',
              'type' => 'empty_spaces_before_argument'
            }
          }
        },
        'end_command' => {
          'cmdname' => 'end',
          'extra' => {
            'command' => {},
            'command_argument' => 'float',
            'text_arg' => 'float'
          }
        },
        'normalized' => 'premi_00e8re-entr_00e9e',
        'type' => {
          'content' => [
            {
              'text' => 'entr'
            },
            {
              'cmdname' => '\''
            },
            {
              'text' => 'e'
            }
          ],
          'normalized' => 'entr_00e9e'
        }
      },
      'number' => 1
    }
  ]
};
$result_floats{'float_with_at_commands'}{'entr_00e9e'}[0]{'extra'}{'caption'}{'extra'}{'float'} = $result_floats{'float_with_at_commands'}{'entr_00e9e'}[0];
$result_floats{'float_with_at_commands'}{'entr_00e9e'}[0]{'extra'}{'end_command'}{'extra'}{'command'} = $result_floats{'float_with_at_commands'}{'entr_00e9e'}[0];



$result_converted{'plaintext'}->{'float_with_at_commands'} = 'Ceci est notre premie`re entre\'e.

entre\'e 1: La premie`re entre\'e est importante

* Menu:

* entre\'e 1: premie`re entre\'e.          La premie`re entre\'e est ...

';


$result_converted{'html'}->{'float_with_at_commands'} = '<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
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
<div class="float"><a name="premi_00e8re-entr_00e9e"></a>

<p>Ceci est notre premi&egrave;re entr&eacute;e.
</p>

<div class="float-caption"><p><strong>entr&eacute;e 1: </strong>La premi&egrave;re entr&eacute;e est importante</p></div></div>

<dl class="listoffloats">
<dt><a href="#premi_00e8re-entr_00e9e">entr&eacute;e 1</a></dt><dd><p>La premi&egrave;re entr&eacute;e est importante</p></dd>
</dl>



</body>
</html>
';

$result_converted_errors{'html'}->{'float_with_at_commands'} = [
  {
    'error_line' => 'warning: Must specify a title with a title command or @top
',
    'text' => 'Must specify a title with a title command or @top',
    'type' => 'warning'
  }
];


1;
