project('cbp2025_exact', 'cpp',
        version : '0.1',
        default_options : ['warning_level=3', 'cpp_std=c++17'])

zdep = dependency('zlib')
cbp = static_library('cbp', [
                  'lib/bp.cc',
                  'lib/cache.cc',
                  'lib/cbp.cc',
                  'lib/gzstream.cc',
                  'lib/my_value_predictor.cc',
                  'lib/parameters.cc',
                  'lib/resource_schedule.cc',
                  'lib/uarchsim.cc'
              ],
              include_directories : include_directories('lib'),
              dependencies : zdep, cpp_args : ['-DGZSTREAM_NAMESPACE=gz'])

executable('cbp2025_exact',
           'cond_branch_predictor_interface.cc',
           'my_cond_branch_predictor.cc',
           install : true, link_with: cbp)
