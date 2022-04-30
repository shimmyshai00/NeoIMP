#ifndef SDF_COMMON_PIPELINE_PIPELINE_HPP
#define SDF_COMMON_PIPELINE_PIPELINE_HPP

// (C) 2020-2022. All rights reserved. See LICENSE for legal and redistribution terms.
//
// AUTHOR:  Shimrra Shai
// PROJECT: NeoIMP
// FILE:    Pipeline.hpp
// PURPOSE: Defines a structure for representing pipelines.

#include <functional>

namespace SDF::Common::Pipeline {
    // It consumes things.
    template <class T>
    using Sink = std::function<void(const T &)>;

    // It springs forth.
    template <class T>
    using Source = std::function<T()>;

    // It uses the source to feed the sink.
    template <class T>
    using Process = std::function<void(Source<T>, Sink<T>)>;

    // A pipeline, which runs by itself to perform an operation.
    template <class T>
    using Pipeline = std::function<void()>;

    template <class T>
    using ImmaturePipeline = std::function<void(Sink<T> &)>;

    // Begin building the pipeline from a source.
    template <class T>
    ImmaturePipeline<T> operator|(Source<T> a_source, Process<T> a_process) {
        return [=](Sink<T> &b_sink) { a_process(a_source, b_sink); };
    }

    // Extend the pipeline.
    template <class T>
    ImmaturePipeline<T> operator|(ImmaturePipeline<T> a_pip, Process<T> a_process) {
        return [=](Sink<T> b_sink) { a_pip([=](const T &b_val) { a_process([=]() { return b_val; }, b_sink); }); };
    }

    // Complete the pipeline.
    template <class T>
    Pipeline<T> operator|(ImmaturePipeline<T> a_pip, Sink<T> a_sink) {
        return [=]() { a_pip(a_sink); };
    }
}  // namespace SDF::Common::Pipeline

#endif  // SDF_COMMON_PIPELINE_PIPELINE_HPP