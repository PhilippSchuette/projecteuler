#!/bin/sh
# create code coverage report
# options="1,2:9"
for file in target/debug/rust_src*; do [ -x "${file}" ] || continue; mkdir -p "target/cov/$(basename $file)"; kcov --exclude-pattern=/.cargo,/usr,/lib64 --verify "target/cov/$(basename $file)" "$file" $options; done

# another run without options, otherwise `cargo test $options' is
# interpreted as a test name pattern and all tests are filtered out
for file in target/debug/rust_src*; do [ -x "${file}" ] || continue; mkdir -p "target/cov/$(basename $file)"; kcov --exclude-pattern=/.cargo,/usr,/lib64 --verify "target/cov/$(basename $file)" "$file"; done
