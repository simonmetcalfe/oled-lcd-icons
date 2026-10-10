"""ESPHome external component for the icons library.

An `oli_icons:` entry in the YAML loads this component. ESPHome then copies the headers in
this folder into the build and includes them in esphome.h, so display lambdas can use
oli::icons_8x8::..., oli::frame(), oli::draw() and so on. There is nothing to configure or generate.
"""

import esphome.config_validation as cv

DEPENDENCIES = ["display"]

CONFIG_SCHEMA = cv.Schema({})


async def to_code(config):
    pass
