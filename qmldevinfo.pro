TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS += src

!isEmpty(ENABLE_EXAMPLES) {
    SUBDIRS += example
    example.depends = src
}

export(PREFIX)


