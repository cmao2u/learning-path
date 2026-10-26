import torch
import torch.nn as nn

model = nn.Sequential(
    nn.Conv2d(3,8, kernel_size=3, stride=1, padding=1),
    nn.ReLU(),
    nn.MaxPool2d(kernel_size=2, stride=2),
    nn.Conv2d(8,16, kernel_size=3, stride=1, padding=1),
    nn.ReLU(),
    nn.MaxPool2d(kernel_size=2, stride=2),
    nn.Flatten(),
    nn.Linear(16*8*8, 15)
)

# 生成四份形状与 RGB 图片相同的随机数据
x = torch.randn(4, 3, 32, 32)

with torch.no_grad():
    outputs = model(x)

print("输入形状：", x.shape)
print("输出形状：", outputs.shape)