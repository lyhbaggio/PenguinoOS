use vars qw(%result_texis %result_texts %result_trees %result_errors 
   %result_indices %result_sectioning %result_nodes %result_menus
   %result_floats %result_converted %result_converted_errors 
   %result_elements %result_directions_text);

use utf8;

$result_trees{'nodes_after_top_before_chapter_sections'} = [
  {
    'contents' => [
      {
        'contents' => [],
        'parent' => {},
        'type' => 'text_root'
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
                'text' => 'Top'
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
        'cmdname' => 'node',
        'contents' => [
          {
            'contents' => [
              {
                'parent' => {},
                'text' => 'Top node
'
              }
            ],
            'parent' => {},
            'type' => 'paragraph'
          },
          {
            'cmdname' => 'menu',
            'contents' => [
              {
                'extra' => {
                  'command' => {}
                },
                'parent' => {},
                'text' => '
',
                'type' => 'empty_line_after_command'
              },
              {
                'args' => [
                  {
                    'parent' => {},
                    'text' => '* ',
                    'type' => 'menu_entry_leading_text'
                  },
                  {
                    'contents' => [
                      {
                        'parent' => {},
                        'text' => 'second node'
                      }
                    ],
                    'parent' => {},
                    'type' => 'menu_entry_node'
                  },
                  {
                    'parent' => {},
                    'text' => '::',
                    'type' => 'menu_entry_separator'
                  },
                  {
                    'contents' => [
                      {
                        'contents' => [
                          {
                            'parent' => {},
                            'text' => '
'
                          }
                        ],
                        'parent' => {},
                        'type' => 'preformatted'
                      }
                    ],
                    'parent' => {},
                    'type' => 'menu_entry_description'
                  }
                ],
                'extra' => {
                  'menu_entry_description' => {},
                  'menu_entry_node' => {
                    'node_content' => [
                      {}
                    ],
                    'normalized' => 'second-node'
                  }
                },
                'line_nr' => {
                  'file_name' => '',
                  'line_nr' => 4,
                  'macro' => ''
                },
                'parent' => {},
                'type' => 'menu_entry'
              },
              {
                'args' => [
                  {
                    'parent' => {},
                    'text' => '* ',
                    'type' => 'menu_entry_leading_text'
                  },
                  {
                    'contents' => [
                      {
                        'parent' => {},
                        'text' => 'third node'
                      }
                    ],
                    'parent' => {},
                    'type' => 'menu_entry_node'
                  },
                  {
                    'parent' => {},
                    'text' => '::',
                    'type' => 'menu_entry_separator'
                  },
                  {
                    'contents' => [
                      {
                        'contents' => [
                          {
                            'parent' => {},
                            'text' => '
'
                          }
                        ],
                        'parent' => {},
                        'type' => 'preformatted'
                      }
                    ],
                    'parent' => {},
                    'type' => 'menu_entry_description'
                  }
                ],
                'extra' => {
                  'menu_entry_description' => {},
                  'menu_entry_node' => {
                    'node_content' => [
                      {}
                    ],
                    'normalized' => 'third-node'
                  }
                },
                'line_nr' => {
                  'file_name' => '',
                  'line_nr' => 5,
                  'macro' => ''
                },
                'parent' => {},
                'type' => 'menu_entry'
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
                        'text' => 'menu'
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
                  'command_argument' => 'menu',
                  'spaces_after_command' => {},
                  'text_arg' => 'menu'
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
              'end_command' => {},
              'spaces_after_command' => {}
            },
            'line_nr' => {
              'file_name' => '',
              'line_nr' => 3,
              'macro' => ''
            },
            'parent' => {}
          },
          {
            'parent' => {},
            'text' => '
',
            'type' => 'empty_line'
          }
        ],
        'extra' => {
          'node_content' => [
            {}
          ],
          'nodes_manuals' => [
            {
              'node_content' => [],
              'normalized' => 'Top'
            }
          ],
          'normalized' => 'Top',
          'spaces_after_command' => {}
        },
        'line_nr' => {
          'file_name' => '',
          'line_nr' => 1,
          'macro' => ''
        },
        'parent' => {}
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
                'text' => 'second node'
              }
            ],
            'parent' => {},
            'type' => 'misc_line_arg'
          },
          {
            'contents' => [
              {
                'text' => ' ',
                'type' => 'empty_spaces_before_argument'
              },
              {
                'parent' => {},
                'text' => 'third node'
              }
            ],
            'parent' => {},
            'type' => 'misc_line_arg'
          },
          {
            'contents' => [
              {
                'parent' => {},
                'text' => 'Top'
              }
            ],
            'parent' => {},
            'type' => 'misc_line_arg'
          },
          {
            'contents' => [
              {
                'parent' => {},
                'text' => 'Top'
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
        'cmdname' => 'node',
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
                'text' => 'second node
'
              }
            ],
            'parent' => {},
            'type' => 'paragraph'
          },
          {
            'parent' => {},
            'text' => '
',
            'type' => 'empty_line'
          }
        ],
        'extra' => {
          'node_content' => [
            {}
          ],
          'nodes_manuals' => [
            {
              'node_content' => [],
              'normalized' => 'second-node'
            },
            {
              'node_content' => [
                {}
              ],
              'normalized' => 'third-node'
            },
            {
              'node_content' => [
                {}
              ],
              'normalized' => 'Top'
            },
            {
              'node_content' => [
                {}
              ],
              'normalized' => 'Top'
            }
          ],
          'normalized' => 'second-node',
          'spaces_after_command' => {}
        },
        'line_nr' => {
          'file_name' => '',
          'line_nr' => 8,
          'macro' => ''
        },
        'parent' => {}
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
                'text' => 'third node'
              }
            ],
            'parent' => {},
            'type' => 'misc_line_arg'
          },
          {
            'contents' => [],
            'parent' => {},
            'type' => 'misc_line_arg'
          },
          {
            'contents' => [
              {
                'parent' => {},
                'text' => 'second node'
              }
            ],
            'parent' => {},
            'type' => 'misc_line_arg'
          },
          {
            'contents' => [
              {
                'parent' => {},
                'text' => 'Top'
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
        'cmdname' => 'node',
        'contents' => [],
        'extra' => {
          'node_content' => [
            {}
          ],
          'nodes_manuals' => [
            {
              'node_content' => [],
              'normalized' => 'third-node'
            },
            undef,
            {
              'node_content' => [
                {}
              ],
              'normalized' => 'second-node'
            },
            {
              'node_content' => [
                {}
              ],
              'normalized' => 'Top'
            }
          ],
          'normalized' => 'third-node',
          'spaces_after_command' => {}
        },
        'line_nr' => {
          'file_name' => '',
          'line_nr' => 12,
          'macro' => ''
        },
        'parent' => {}
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
                'text' => 'chapter'
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
        'cmdname' => 'chapter',
        'contents' => [],
        'extra' => {
          'misc_content' => [
            {}
          ],
          'spaces_after_command' => {}
        },
        'level' => 1,
        'line_nr' => {
          'file_name' => '',
          'line_nr' => 13,
          'macro' => ''
        },
        'number' => 1,
        'parent' => {}
      }
    ],
    'extra' => {
      'element_command' => {},
      'node' => {},
      'section' => {}
    },
    'type' => 'element'
  }
];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'args'}[0]{'contents'}[0]{'extra'}{'command'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'args'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'args'}[0]{'contents'}[1]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'args'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'args'}[0]{'contents'}[2]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'args'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'args'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[0]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[0]{'extra'}{'command'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1]{'args'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1]{'args'}[1]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1]{'args'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1]{'args'}[1]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1]{'args'}[2]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1]{'args'}[3]{'contents'}[0]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1]{'args'}[3]{'contents'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1]{'args'}[3]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1]{'args'}[3];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1]{'args'}[3]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1]{'extra'}{'menu_entry_description'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1]{'args'}[3];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1]{'extra'}{'menu_entry_node'}{'node_content'}[0] = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1]{'args'}[1]{'contents'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[1]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2]{'args'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2]{'args'}[1]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2]{'args'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2]{'args'}[1]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2]{'args'}[2]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2]{'args'}[3]{'contents'}[0]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2]{'args'}[3]{'contents'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2]{'args'}[3]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2]{'args'}[3];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2]{'args'}[3]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2]{'extra'}{'menu_entry_description'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2]{'args'}[3];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2]{'extra'}{'menu_entry_node'}{'node_content'}[0] = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2]{'args'}[1]{'contents'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[2]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[3]{'args'}[0]{'contents'}[0]{'extra'}{'command'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[3];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[3]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[3]{'args'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[3]{'args'}[0]{'contents'}[1]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[3]{'args'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[3]{'args'}[0]{'contents'}[2]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[3]{'args'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[3]{'args'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[3];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[3]{'extra'}{'command'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[3]{'extra'}{'spaces_after_command'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[3]{'args'}[0]{'contents'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[3]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'extra'}{'end_command'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[3];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'extra'}{'spaces_after_command'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'contents'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[1]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'contents'}[2]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'extra'}{'node_content'}[0] = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'args'}[0]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'extra'}{'nodes_manuals'}[0]{'node_content'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'extra'}{'node_content'};
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'extra'}{'spaces_after_command'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'args'}[0]{'contents'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[1]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0]{'extra'}{'command'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[0]{'contents'}[1]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[1]{'contents'}[1]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[1]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[2]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[2];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[2]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[3]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[3];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[3]{'contents'}[1]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[3];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[3]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'contents'}[1]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'contents'}[1]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'contents'}[2]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'extra'}{'node_content'}[0] = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[0]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'extra'}{'nodes_manuals'}[0]{'node_content'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'extra'}{'node_content'};
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'extra'}{'nodes_manuals'}[1]{'node_content'}[0] = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[1]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'extra'}{'nodes_manuals'}[2]{'node_content'}[0] = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[2]{'contents'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'extra'}{'nodes_manuals'}[3]{'node_content'}[0] = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[3]{'contents'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'extra'}{'spaces_after_command'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'args'}[0]{'contents'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[2]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[0]{'contents'}[0]{'extra'}{'command'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[0]{'contents'}[1]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[1]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[2]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[2];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[2]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[3]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[3];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[3]{'contents'}[1]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[3];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[3]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'extra'}{'node_content'}[0] = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[0]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'extra'}{'nodes_manuals'}[0]{'node_content'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'extra'}{'node_content'};
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'extra'}{'nodes_manuals'}[2]{'node_content'}[0] = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[2]{'contents'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'extra'}{'nodes_manuals'}[3]{'node_content'}[0] = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[3]{'contents'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'extra'}{'spaces_after_command'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'args'}[0]{'contents'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[4]{'args'}[0]{'contents'}[0]{'extra'}{'command'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[4];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[4]{'args'}[0]{'contents'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[4]{'args'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[4]{'args'}[0]{'contents'}[1]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[4]{'args'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[4]{'args'}[0]{'contents'}[2]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[4]{'args'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[4]{'args'}[0]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[4];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[4]{'extra'}{'misc_content'}[0] = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[4]{'args'}[0]{'contents'}[1];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[4]{'extra'}{'spaces_after_command'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[4]{'args'}[0]{'contents'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[4]{'parent'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'extra'}{'element_command'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[4];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'extra'}{'node'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[3];
$result_trees{'nodes_after_top_before_chapter_sections'}[0]{'extra'}{'section'} = $result_trees{'nodes_after_top_before_chapter_sections'}[0]{'contents'}[4];

$result_texis{'nodes_after_top_before_chapter_sections'} = '@node Top
Top node
@menu
* second node::
* third node::
@end menu

@node second node, third node,Top,Top

second node

@node third node,,second node,Top
@chapter chapter
';


$result_texts{'nodes_after_top_before_chapter_sections'} = 'Top node
* second node::
* third node::


second node

1 chapter
*********
';

$result_sectioning{'nodes_after_top_before_chapter_sections'} = {
  'level' => 0,
  'section_childs' => [
    {
      'cmdname' => 'chapter',
      'extra' => {
        'associated_node' => {
          'cmdname' => 'node',
          'extra' => {
            'normalized' => 'third-node'
          }
        }
      },
      'level' => 1,
      'number' => 1,
      'section_up' => {}
    }
  ]
};
$result_sectioning{'nodes_after_top_before_chapter_sections'}{'section_childs'}[0]{'section_up'} = $result_sectioning{'nodes_after_top_before_chapter_sections'};

$result_nodes{'nodes_after_top_before_chapter_sections'} = {
  'cmdname' => 'node',
  'extra' => {
    'normalized' => 'Top'
  },
  'menu_child' => {
    'cmdname' => 'node',
    'extra' => {
      'normalized' => 'second-node'
    },
    'node_next' => {
      'cmdname' => 'node',
      'extra' => {
        'associated_section' => {
          'cmdname' => 'chapter',
          'extra' => {},
          'level' => 1,
          'number' => 1
        },
        'normalized' => 'third-node'
      },
      'node_prev' => {},
      'node_up' => {}
    },
    'node_prev' => {},
    'node_up' => {}
  },
  'menus' => [
    {
      'cmdname' => 'menu',
      'extra' => {
        'end_command' => {
          'cmdname' => 'end',
          'extra' => {
            'command' => {},
            'command_argument' => 'menu',
            'text_arg' => 'menu'
          }
        }
      }
    }
  ],
  'node_next' => {},
  'node_up' => {
    'extra' => {
      'manual_content' => [
        {
          'text' => 'dir'
        }
      ],
      'top_node_up' => {}
    },
    'type' => 'top_node_up'
  }
};
$result_nodes{'nodes_after_top_before_chapter_sections'}{'menu_child'}{'node_next'}{'node_prev'} = $result_nodes{'nodes_after_top_before_chapter_sections'}{'menu_child'};
$result_nodes{'nodes_after_top_before_chapter_sections'}{'menu_child'}{'node_next'}{'node_up'} = $result_nodes{'nodes_after_top_before_chapter_sections'};
$result_nodes{'nodes_after_top_before_chapter_sections'}{'menu_child'}{'node_prev'} = $result_nodes{'nodes_after_top_before_chapter_sections'};
$result_nodes{'nodes_after_top_before_chapter_sections'}{'menu_child'}{'node_up'} = $result_nodes{'nodes_after_top_before_chapter_sections'};
$result_nodes{'nodes_after_top_before_chapter_sections'}{'menus'}[0]{'extra'}{'end_command'}{'extra'}{'command'} = $result_nodes{'nodes_after_top_before_chapter_sections'}{'menus'}[0];
$result_nodes{'nodes_after_top_before_chapter_sections'}{'node_next'} = $result_nodes{'nodes_after_top_before_chapter_sections'}{'menu_child'};
$result_nodes{'nodes_after_top_before_chapter_sections'}{'node_up'}{'extra'}{'top_node_up'} = $result_nodes{'nodes_after_top_before_chapter_sections'};

$result_menus{'nodes_after_top_before_chapter_sections'} = {
  'cmdname' => 'node',
  'extra' => {
    'normalized' => 'Top'
  },
  'menu_child' => {
    'cmdname' => 'node',
    'extra' => {
      'normalized' => 'second-node'
    },
    'menu_next' => {
      'cmdname' => 'node',
      'extra' => {
        'normalized' => 'third-node'
      },
      'menu_prev' => {},
      'menu_up' => {},
      'menu_up_hash' => {
        'Top' => 1
      }
    },
    'menu_up' => {},
    'menu_up_hash' => {
      'Top' => 1
    }
  }
};
$result_menus{'nodes_after_top_before_chapter_sections'}{'menu_child'}{'menu_next'}{'menu_prev'} = $result_menus{'nodes_after_top_before_chapter_sections'}{'menu_child'};
$result_menus{'nodes_after_top_before_chapter_sections'}{'menu_child'}{'menu_next'}{'menu_up'} = $result_menus{'nodes_after_top_before_chapter_sections'};
$result_menus{'nodes_after_top_before_chapter_sections'}{'menu_child'}{'menu_up'} = $result_menus{'nodes_after_top_before_chapter_sections'};

$result_errors{'nodes_after_top_before_chapter_sections'} = [];


$result_elements{'nodes_after_top_before_chapter_sections'} = [
  {
    'extra' => {
      'directions' => {
        'NodePrev' => {},
        'NodeUp' => {},
        'This' => {}
      },
      'element_command' => {
        'cmdname' => 'chapter',
        'extra' => {},
        'level' => 1,
        'number' => 1
      },
      'node' => {
        'cmdname' => 'node',
        'extra' => {
          'normalized' => 'third-node'
        },
        'menu_prev' => {
          'cmdname' => 'node',
          'extra' => {
            'normalized' => 'second-node'
          },
          'menu_next' => {},
          'menu_up' => {
            'cmdname' => 'node',
            'extra' => {
              'normalized' => 'Top'
            },
            'menu_child' => {}
          },
          'menu_up_hash' => {
            'Top' => 1
          }
        },
        'menu_up' => {},
        'menu_up_hash' => {
          'Top' => 1
        }
      },
      'section' => {}
    },
    'type' => 'element'
  }
];
$result_elements{'nodes_after_top_before_chapter_sections'}[0]{'extra'}{'directions'}{'NodePrev'} = $result_elements{'nodes_after_top_before_chapter_sections'}[0];
$result_elements{'nodes_after_top_before_chapter_sections'}[0]{'extra'}{'directions'}{'NodeUp'} = $result_elements{'nodes_after_top_before_chapter_sections'}[0];
$result_elements{'nodes_after_top_before_chapter_sections'}[0]{'extra'}{'directions'}{'This'} = $result_elements{'nodes_after_top_before_chapter_sections'}[0];
$result_elements{'nodes_after_top_before_chapter_sections'}[0]{'extra'}{'node'}{'menu_prev'}{'menu_next'} = $result_elements{'nodes_after_top_before_chapter_sections'}[0]{'extra'}{'node'};
$result_elements{'nodes_after_top_before_chapter_sections'}[0]{'extra'}{'node'}{'menu_prev'}{'menu_up'}{'menu_child'} = $result_elements{'nodes_after_top_before_chapter_sections'}[0]{'extra'}{'node'}{'menu_prev'};
$result_elements{'nodes_after_top_before_chapter_sections'}[0]{'extra'}{'node'}{'menu_up'} = $result_elements{'nodes_after_top_before_chapter_sections'}[0]{'extra'}{'node'}{'menu_prev'}{'menu_up'};
$result_elements{'nodes_after_top_before_chapter_sections'}[0]{'extra'}{'section'} = $result_elements{'nodes_after_top_before_chapter_sections'}[0]{'extra'}{'element_command'};



$result_directions_text{'nodes_after_top_before_chapter_sections'} = 'element: @chapter chapter
  NodePrev: @chapter chapter
  NodeUp: @chapter chapter
  This: @chapter chapter
';


$result_converted{'info'}->{'nodes_after_top_before_chapter_sections'} = 'This is , produced by tp version from .


File: ,  Node: Top,  Next: second node,  Up: (dir)

Top node
* Menu:

* second node::
* third node::


File: ,  Node: second node,  Next: third node,  Prev: Top,  Up: Top

second node


File: ,  Node: third node,  Prev: second node,  Up: Top

1 chapter
*********



Tag Table:
Node: Top41
Node: second node145
Node: third node229

End Tag Table
';


$result_converted{'html'}->{'nodes_after_top_before_chapter_sections'} = '<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
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
<link href="#Top" rel="start" title="Top">
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
<a name="Top"></a>
<div class="header">
<p>
Next: <a href="#second-node" accesskey="n" rel="next">second node</a>, Up: <a href="dir.html#Top" accesskey="u" rel="up">(dir)</a> &nbsp; </p>
</div>
<h1 class="node-heading">Top</h1>
<p>Top node
</p><table class="menu" border="0" cellspacing="0">
<tr><td align="left" valign="top">&bull; <a href="#second-node" accesskey="1">second node</a>:</td><td>&nbsp;&nbsp;</td><td align="left" valign="top">
</td></tr>
<tr><td align="left" valign="top">&bull; <a href="#third-node" accesskey="2">third node</a>:</td><td>&nbsp;&nbsp;</td><td align="left" valign="top">
</td></tr>
</table>

<hr>
<a name="second-node"></a>
<div class="header">
<p>
Next: <a href="#third-node" accesskey="n" rel="next">third node</a>, Previous: <a href="#Top" accesskey="p" rel="previous">Top</a>, Up: <a href="#Top" accesskey="u" rel="up">Top</a> &nbsp; </p>
</div>
<h4 class="node-heading">second node</h4>

<p>second node
</p>
<hr>
<a name="third-node"></a>
<div class="header">
<p>
Previous: <a href="#second-node" accesskey="p" rel="previous">second node</a>, Up: <a href="#Top" accesskey="u" rel="up">Top</a> &nbsp; </p>
</div>
<a name="chapter"></a>
<h2 class="chapter">1 chapter</h2>
<hr>



</body>
</html>
';

$result_converted_errors{'html'}->{'nodes_after_top_before_chapter_sections'} = [
  {
    'error_line' => 'warning: Must specify a title with a title command or @top
',
    'text' => 'Must specify a title with a title command or @top',
    'type' => 'warning'
  }
];


1;
