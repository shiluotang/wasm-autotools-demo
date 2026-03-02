#!/usr/bin/env bash

declare readonly CURDIR=$(cd $(dirname ${BASH_SOURCE[0]}); pwd -P)
declare readonly TARGET=$(emcc -v 2>&1 | grep "Target" | sed -e "s/Target: //g")

function main() {
    local bindir=bin-${TARGET}
    pushd ${CURDIR} >& /dev/null
    if [[ ! -f ./configure ]]; then
        autoreconf -vfi .
    fi
    if [[ ! -d ${bindir} ]]; then
        mkdir ${bindir}
    fi
    if [[ ! -f ${bindir}/Makefile ]]; then
        pushd ${bindir} >& /dev/null
        local em_pkg_dir=$(dirname $(emconfigure pkg-config --path egl))
        local pkg_dir=$(dirname $(env -i pkg-config --path egl))
        export EM_PKG_CONFIG_PATH=${em_pkg_dir}:${pkg_dir}
        emconfigure ../configure --host=${TARGET}
        popd >& /dev/null
    fi
    if [[ -f ${bindir}/Makefile ]]; then
        make -C ${bindir} clean all check V=1
    fi
    popd >& /dev/null
}

main "${@}"
