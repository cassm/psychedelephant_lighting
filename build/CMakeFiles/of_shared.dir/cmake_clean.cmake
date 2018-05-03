file(REMOVE_RECURSE
  "../bin/ledCylinder.app/Contents/Frameworks/libopenFrameworksShared.pdb"
  "../bin/ledCylinder.app/Contents/Frameworks/libopenFrameworksShared.dylib"
)

# Per-language clean rules from dependency scanning.
foreach(lang C CXX)
  include(CMakeFiles/of_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
