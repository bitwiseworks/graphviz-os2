#!/usr/bin/env bash

set -e
set -o pipefail
set -u
set -x

brew tap --repair
brew update
brew install pango || brew upgrade pango
brew install qt5 || brew upgrade qt5

brew install gtk+ || brew upgrade gtk+
brew install gts || brew upgrade gts

# quoting Homebrew:
#
#   qt@5 is keg-only, which means it was not symlinked into /opt/homebrew,
#   because this is an alternate version of another formula.
#
#   If you need to have qt@5 first in your PATH, run:
#     echo 'export PATH="/opt/homebrew/opt/qt@5/bin:$PATH"' >> ~/.zshrc
#
#   For compilers to find qt@5 you may need to set:
#     export LDFLAGS="-L/opt/homebrew/opt/qt@5/lib"
#     export CPPFLAGS="-I/opt/homebrew/opt/qt@5/include"
#
#   For pkg-config to find qt@5 you may need to set:
#     export PKG_CONFIG_PATH="/opt/homebrew/opt/qt@5/lib/pkgconfig"
export PATH="/opt/homebrew/opt/qt@5/bin:$PATH"
export LDFLAGS="-L/opt/homebrew/opt/qt@5/lib"
export CPPFLAGS="-I/opt/homebrew/opt/qt@5/include"
export PKG_CONFIG_PATH="/opt/homebrew/opt/qt@5/lib/pkgconfig"

brew install librsvg || brew upgrade librsvg
brew install libxaw || brew upgrade libxaw

# install MacPorts for libANN
curl --retry 3 --location --no-progress-meter -O \
  https://github.com/macports/macports-base/releases/download/v2.7.2/MacPorts-2.7.2-12-Monterey.pkg
sudo installer -package MacPorts-2.7.2-12-Monterey.pkg -target /
export PATH=/opt/local/bin:${PATH}

# lib/mingle dependency
sudo port install libANN

python3 -m pip install --requirement requirements.txt
