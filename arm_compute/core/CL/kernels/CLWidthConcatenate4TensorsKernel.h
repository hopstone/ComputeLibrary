/*
 * Copyright (c) 2018 ARM Limited.
 *
 * SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __ARM_COMPUTE_CLWIDTHCONCATENATE_4TENSORS_KERNEL_H__
#define __ARM_COMPUTE_CLWIDTHCONCATENATE_4TENSORS_KERNEL_H__

#include "arm_compute/core/CL/ICLKernel.h"
#include "arm_compute/core/Types.h"

namespace arm_compute
{
class ICLTensor;

/** Interface for the width concatenate kernel of 4 tensors.
 *  All input tensors will be concatenated into the output tensor.
 */
class CLWidthConcatenate4TensorsKernel : public ICLKernel
{
public:
    /** Default constructor */
    CLWidthConcatenate4TensorsKernel();
    /** Prevent instances of this class from being copied (As this class contains pointers) */
    CLWidthConcatenate4TensorsKernel(const CLWidthConcatenate4TensorsKernel &) = delete;
    /** Prevent instances of this class from being copied (As this class contains pointers) */
    CLWidthConcatenate4TensorsKernel &operator=(const CLWidthConcatenate4TensorsKernel &) = delete;
    /** Allow instances of this class to be moved */
    CLWidthConcatenate4TensorsKernel(CLWidthConcatenate4TensorsKernel &&) = default;
    /** Allow instances of this class to be moved */
    CLWidthConcatenate4TensorsKernel &operator=(CLWidthConcatenate4TensorsKernel &&) = default;
    /** Default destructor */
    ~CLWidthConcatenate4TensorsKernel() = default;
    /** Initialise the kernel's input1s and output
     *
     * @param[in]  input1 First input tensor. Data types supported: U8/S8/QASYMM8/U16/S16/F16/U32/S32/F32
     * @param[in]  input2 Second input tensor. Data types supported: same as @p input1
     * @param[in]  input3 Third input tensor. Data types supported: same as @p input1
     * @param[in]  input4 Fourth input tensor. Data types supported: same as @p input1
     * @param[out] output Output tensor. Data types supported: Same as @p input1.
     */
    void configure(const ICLTensor *input1, const ICLTensor *input2, const ICLTensor *input3, const ICLTensor *input4, ICLTensor *output);
    /**  Static function to check if given info will lead to a valid configuration of @ref CLWidthConcatenate4TensorsKernel
     *
     * @param[in] input1 First tensor info. Data types supported: U8/S8/QASYMM8/U16/S16/F16/U32/S32/F32
     * @param[in] input2 Second tensor info. Data types supported: same as @p input1
     * @param[in] input3 Third tensor info. Data types supported: same as @p input1
     * @param[in] input4 Fourth tensor info. Data types supported: same as @p input1
     * @param[in] output Output tensor info. Data types supported: Same as @p input1.
     *
     * @return a status
     */
    static Status validate(const ITensorInfo *input1, const ITensorInfo *input2, const ITensorInfo *input3, const ITensorInfo *input4, const ITensorInfo *output);

    // Inherited methods overridden:
    void run(const Window &window, cl::CommandQueue &queue) override;

private:
    const ICLTensor *_input1;
    const ICLTensor *_input2;
    const ICLTensor *_input3;
    const ICLTensor *_input4;
    ICLTensor       *_output;
};
} // namespace arm_compute
#endif /* __ARM_COMPUTE_CLWIDTHCONCATENATE_4TENSORS_KERNEL_H__ */