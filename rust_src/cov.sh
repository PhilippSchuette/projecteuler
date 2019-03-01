#!/bin/sh
# Create code coverage report for CodeCov with `kcov'.
# define cli options and exclude pattern
options="1,2:9"
exclude_pattern="#no_code"

# run command once with exclude pattern and options
for file in target/debug/rust_src*; do [ -x "${file}" ] || continue; mkdir -p "target/cov/$(basename $file)"; kcov --exclude-line=$exclude_pattern --exclude-pattern=/.cargo,/usr,/lib64 --verify "target/cov/$(basename $file)" "$file" $options; done

# another run without options, otherwise `cargo test $options' is
# interpreted as a test name pattern and all tests are filtered out
for file in target/debug/rust_src*; do [ -x "${file}" ] || continue; mkdir -p "target/cov/$(basename $file)"; kcov --exclude-line=$exclude_pattern --exclude-pattern=/.cargo,/usr,/lib64 --verify "target/cov/$(basename $file)" "$file"; done
