
uniform float iGlobalTime;
uniform vec2 iResolution;
uniform float direction;
uniform float speed;

float noise(vec2 pos)
{
	return fract(1111. * sin(111. * dot(pos, vec2(2222., 22.))));
}

void main()
{
	float rings = 12.0;
	float vel=20.;
	float b = 0.0005;
	vec2 position = ( gl_FragCoord.xy / iResolution.xy );
    float aspect = iResolution.x / iResolution.y;
	position.x *= aspect;
	float dist = distance(position, vec2(aspect*0.5, 0.5));
	float mr=0.5;
	float conv=(rings*2.+1.)/mr;
	//conv*=cos(position.x)*fract(cos(dist)*2.)*(sin(iGlobalTime*0.15)*09.05);//deformacion
	float v=dist*conv-iGlobalTime*vel;
	float ringr=floor(v);
	float color=smoothstep(-b, b, abs(dist- (ringr+float(fract(v)>0.5)+iGlobalTime*vel)/conv) );
	if(mod(ringr,2.)==1.)
    color=1.-color;
	//comment this line for no noise
	//color= (color*0.70 + noise((position*2.-1.)*0.001 + 0.00001) * 0.5);
    
	//strobe
    vec2 p = (gl_FragCoord.xy / iResolution.xy - vec2(0.5, 0.5)) * 2.0;
    float t = mod(iGlobalTime*speed, 3.0);
    
    float x = p.x * p.x;
    float ys = p.y;
    float c = 1.0;
    float vs = t * t * t * t * t * 2.3;
    float w = abs(ys) + x / 100.0;
    
    if(direction<2.0){
        w = abs(ys) + x / 100.0;
    } else {
        w = abs(x) + x / 100.0;
    }
    
    if (vs > 1.0) {
        c = (1.5 - t) * 2.0;
    } else if (v > w) {
        c = 1.0;
    } else {
        c = vs * vs / w / w;
    }
    
    float r = sin(x) * cos(x) * x * 0.2;
    
    gl_FragColor.a = 1.0;
    gl_FragColor.rgb = vec3(c-r, c-r, c);
    
    
    vec4 finalTex = mix(vec4(color,color,color,1.0),vec4(c-r,c-r,c,1.0),0.50);
	gl_FragColor = vec4( finalTex );
    
}


