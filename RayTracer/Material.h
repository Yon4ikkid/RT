#pragma once

class Material
{
private:
	float __reflection;
	float __diffusion;
	int __rgb[3];

public:
	Material();
	Material(const int r, const int g, const int b);
	Material(const int r, const int g, const int b, const float ref, const float dif);
	Material(const int rgb[3], const float ref, const float dif);

	float GetReflection() const;
	float GetDiffusion() const;
	int* GetRGB() const;
	int GetR() const;
	int GetG() const;
	int GetB() const;

	void SetReflection(const float ref);
	void SetDiffusion(const float dif);
	void SetRGB(const int rgb[3]);
	void SetRGB(const int r, const int g, const int b);
};
