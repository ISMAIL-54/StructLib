file(REMOVE_RECURSE
  "libSL.a"
  "libSL.pdb"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/SL.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
