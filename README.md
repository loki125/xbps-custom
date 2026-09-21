# xbps-custom

**xbps-custom** is an unofficial Void Linux extension for creating, building, installing, and diagnosing custom XBPS packages using the `void-packages` repository. It provides a simple CLI for the common packaging tasks while keeping the existing Void Linux packaging tools underneath. The project is focused on being lightweight, understandable, and useful for people who want to keep their custom software native to Void Linux. **This project is currently unofficial and experimental.**

## Features

* **Automatic `void-packages` setup**
  Automatically downloads and keeps a local copy of the `void-packages` repository ready to use.

* **Simple CLI**
  Provides an easy interface for common tasks such as creating templates, building packages, installing packages, and managing the local environment.

* **Template helper**
  Helps create and prepare `void-packages` templates for software that isn't available in the official repositories.

* **Local package repository**
  Automatically synchronizes locally built `.xbps` packages with a local XBPS repository, using hard links where possible to avoid unnecessary copies.

* **Dependency diagnostics**
  Inspects package builds and applications to help identify dependency problems, including shared libraries, SONAMEs, bundled libraries, and missing build dependencies.

* **Template validation**
  Checks templates for common problems before building and provides useful information about issues that may prevent a package from building correctly.

* **Package status**
  Keeps track of locally built packages and makes it easier to see their current state.

The project aims to stay small and avoid unnecessary features. The goal is to make packaging software for your own Void system less of a hassle, while keeping the resulting packages native and managed through XBPS.
