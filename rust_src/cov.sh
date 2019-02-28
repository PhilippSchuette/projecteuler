#!/bin/sh
# create code coverage report
for file in target/debug/rust_src*; do [ -x "${file}" ] || continue; mkdir -p "target/cov/$(basename $file)"; kcov --exclude-pattern=/.cargo,/usr,/lib64,merged --verify "target/cov/$(basename $file)" "$file"; done
