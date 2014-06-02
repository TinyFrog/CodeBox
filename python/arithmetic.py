#show type
print type(3.0)

# type conversion
print int(3.14159), int(-2.0)
print float(18)

# This would throw approximation error since python cannot handle more 12 decimal digits
# python would return 3.14159262305
print 3.14159262304802408423


# division
# if one operand is decimal, the result would decimal
print 1.0 / 3
print 1 / 3

# this is valid!
print 7/+4
