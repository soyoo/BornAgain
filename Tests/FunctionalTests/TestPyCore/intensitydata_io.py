# tests of IO operations with the IntensityData object

import sys
import os
import unittest
import numpy
import math
import time

sys.path.append(os.path.abspath(
                os.path.join(os.path.split(__file__)[0],
                '..', '..', '..', 'lib')))

from libBornAgainCore import *


def fill_data(data):
    """
    Fills intensity data with some numbers
    """
    for i in range(0, data.getAllocatedSize()):
        data[i] = i


def is_the_same_data(data1, data2):
    """
    Checks if two data are identical
    """
    if data1.getAllocatedSize() != data2.getAllocatedSize():
        return False
    if data1.getRank() != data2.getRank():
        return False
    for i in range(0, data1.getRank()):
        if data1.getAxis(i) != data2.getAxis(i):
            return False
    for i in range(0, data1.getAllocatedSize()):
        if data1[i] != data2[i]:
            return False

    return True


def get_boundaries_flat_in_sin(nbins, start, end):
    """
    Returns flat_in_sin binning of angle axis
    """
    result = []
    start_sin = math.sin( deg2rad(start))
    end_sin = math.sin( deg2rad(end))
    step = (end_sin - start_sin)/nbins
    for i in range(0, nbins+1):
        result.append( rad2deg(math.asin(start_sin + step*i)))
    return result




class OutputDataIOTest(unittest.TestCase):
    """
    Test serialization of IntensityData
    """
    def test_01_FixedBinAxis_1D(self):
        data = IntensityData()
        data.addAxis(FixedBinAxis("axis0", 10, -1.00000001, 1.0))
        fill_data(data)
        OutputDataIOFactory.writeIntensityData(data, "tmp.baint")
        newdata = OutputDataIOFactory.readIntensityData("tmp.baint")
        self.assertTrue(is_the_same_data(data, newdata))

    def test_02_FixedBinAxis_2D(self):
        data = IntensityData()
        data.addAxis(FixedBinAxis("axis0", 9, -1.00000001, 1.0))
        data.addAxis(FixedBinAxis("axis1", 3, -4.0, 5.0))
        fill_data(data)
        OutputDataIOFactory.writeIntensityData(data, "tmp.baint")
        newdata = OutputDataIOFactory.readIntensityData("tmp.baint")
        self.assertTrue(is_the_same_data(data, newdata))

    def test_03_FixedBinAxis_3D(self):
        data = IntensityData()
        data.addAxis(FixedBinAxis("axis0", 9, -1.00000001, 1.0))
        data.addAxis(FixedBinAxis("axis1", 1, -4.0, 5.0))
        data.addAxis(FixedBinAxis("axis2", 3, 0.0, 1.0))
        fill_data(data)
        OutputDataIOFactory.writeIntensityData(data, "tmp.baint")
        newdata = OutputDataIOFactory.readIntensityData("tmp.baint")
        self.assertTrue(is_the_same_data(data, newdata))

    def test_04_VariableBinAxis_1D(self):
        data = IntensityData()
        data.addAxis(VariableBinAxis("axis0", 10, get_boundaries_flat_in_sin(10, -5.0, 5.0)))
        fill_data(data)
        OutputDataIOFactory.writeIntensityData(data, "tmp.baint")
        newdata = OutputDataIOFactory.readIntensityData("tmp.baint")
        self.assertTrue(is_the_same_data(data, newdata))

    def test_05_VariableBinAxis_2D(self):
        data = IntensityData()
        data.addAxis(VariableBinAxis("axis0", 10, get_boundaries_flat_in_sin(10, -5.0, 5.0)))
        data.addAxis(VariableBinAxis("axis1", 3, get_boundaries_flat_in_sin(3, 0.0, 2.0)))
        fill_data(data)
        OutputDataIOFactory.writeIntensityData(data, "tmp.baint")
        newdata = OutputDataIOFactory.readIntensityData("tmp.baint")
        self.assertTrue(is_the_same_data(data, newdata))

    def test_06_VariableAndFixedMix(self):
        data = IntensityData()
        data.addAxis(FixedBinAxis("axis0", 10, -5.0, 5.0))
        data.addAxis(VariableBinAxis("axis1", 3, get_boundaries_flat_in_sin(3, 0.0, 2.0)))
        fill_data(data)
        OutputDataIOFactory.writeIntensityData(data, "tmp.baint")
        newdata = OutputDataIOFactory.readIntensityData("tmp.baint")
        self.assertTrue(is_the_same_data(data, newdata))

    def test_07_ConstKBinAxis_2D(self):
        data = IntensityData()
        data.addAxis(ConstKBinAxis("axis0", 9, -1.00000001*degree, 1.0*degree))
        data.addAxis(ConstKBinAxis("axis1", 3, -4.0*degree, 5.0*degree))
        fill_data(data)
        OutputDataIOFactory.writeIntensityData(data, "tmp.baint")
        newdata = OutputDataIOFactory.readIntensityData("tmp.baint")
        self.assertTrue(is_the_same_data(data, newdata))

    def test_08_IsGisaxsAxis_2D(self):
        data = IntensityData()
        data.addAxis(IsGisaxsAxis("axis0", 9, -1.00000001*degree, 1.0*degree))
        data.addAxis(IsGisaxsAxis("axis1", 3, -4.0*degree, 5.0*degree))
        fill_data(data)
        OutputDataIOFactory.writeIntensityData(data, "tmp.baint")
        newdata = OutputDataIOFactory.readIntensityData("tmp.baint")
        self.assertTrue(is_the_same_data(data, newdata))


if __name__ == '__main__':
    unittest.main()
