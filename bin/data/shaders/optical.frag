
uniform float iGlobalTime;
uniform vec2 iResolution;

uniform float direction;
uniform float speed;

uniform float amplitude;
uniform float seperation;
uniform float glow;
uniform float waveSpeed;

vec3 COLOR1 = vec3(0.0, 0.0, 0.3);
vec3 COLOR2 = vec3(0.5, 0.0, 0.0);
float BLOCK_WIDTH = 0.01;

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
    
    //Wave
    vec2 uv = gl_FragCoord.xy / iResolution.xy;

    // To create the BG pattern
	vec3 final_color = vec3(1.0);
	vec3 wave_color = vec3(0.0);
	
	float c1 = mod(uv.x, 2.0 * BLOCK_WIDTH);
	c1 = step(BLOCK_WIDTH, c1);
	
	float c2 = mod(uv.y, 2.0 * BLOCK_WIDTH);
	c2 = step(BLOCK_WIDTH, c2);
    
	// To create the waves
	float wave_width = 0.01;
	uv  = -1.0 + 2.0 * uv;
	uv.y += 0.1;
	for(float i = 0.0; i < 10.0; i++) {
		
		uv.y += (amplitude * sin(uv.x + i/seperation + iGlobalTime * waveSpeed));
		wave_width = abs(1.0 / (glow * uv.y));
		wave_color += vec3(wave_width * 1.9, wave_width, wave_width * 1.5);
	}
	
	final_color = wave_color;
	
//	gl_FragColor = vec4(final_color,1.0) );
//	gl_FragColor = vec4( finalTex * vec4(final_color,1.0) );
	gl_FragColor = vec4( 1.0 * vec4(final_color,1.0) );

}


