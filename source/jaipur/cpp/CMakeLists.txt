set(source_directory source)

set(JAIPUR_SOURCES
  ${source_directory}/main.cpp
)
list(SORT JAIPUR_SOURCES)

add_executable(jaipur
  ${JAIPUR_SOURCES}
)

add_dependencies(jaipur
  ardupilotmega.xml-v1.0
)
