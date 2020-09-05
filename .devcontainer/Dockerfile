# Use the [Choice] comment to indicate option arguments that should appear in VS Code UX
#
# [Choice] Debian OS version: buster, stretch
# ARG VARIANT="buster"
FROM archlinux:latest

# Install needed packages and setup non-root user. Use a separate RUN statement to add your own dependencies.
ARG USERNAME=vscode
ARG USER_UID=1000
ARG USER_GID=$USER_UID
COPY library-scripts/*.sh /tmp/library-scripts/
RUN pacman -Syu --noconfirm\
    && /bin/bash /tmp/library-scripts/common-arch.sh "${USERNAME}" "${USER_UID}" "${USER_GID}"
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && /bin/bash /tmp/library-scripts/common-debian.sh "${INSTALL_ZSH}" "${USERNAME}" "${USER_UID}" "${USER_GID}" "${UPGRADE_PACKAGES}" \
#     #
#     # ****************************************************************************
#     # * TODO: Add any additional OS packages you want included in the definition *
#     # * here. We want to do this before cleanup to keep the "layer" small.       *
#     # ****************************************************************************
#     # && apt-get -y install --no-install-recommends <your-package-list-here> \
#     #
#     && apt-get autoremove -y && apt-get clean -y && rm -rf /var/lib/apt/lists/* /tmp/library-scripts

# [Optional] Uncomment this section to install additional OS packages.
# Install main packages
RUN pacman -Syu --noconfirm git
# Install main packages for c++ development
RUN pacman -Syu --noconfirm gcc clang llvm lldb cmake cppcheck valgrind
# Install misc packages
RUN pacman -Syu --noconfirm time