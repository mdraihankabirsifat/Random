import React, { useState, useEffect, useCallback } from 'react';

interface Ball {
    id: number;
    char: string;
    x: number;
    y: number;
    dx: number;
    dy: number;
    type: 'lowercase' | 'uppercase' | 'number' | 'odd' | 'even';
    color: string;
}

const WorstCaptcha = () => {
    const [balls, setBalls] = useState<Ball[]>(() => {
        // Ensure we have at least 2 of each type
        const lowercaseChars = 'abcdefghjkmnpqrstuvwxyz';
        const uppercaseChars = 'ABCDEFGHJKLMNPQRSTUVWXYZ';
        const oddNumbers = '13579';
        const evenNumbers = '02468';

        const colors: Record<Ball['type'], string> = {
            lowercase: '#ff6b6b',
            uppercase: '#4ecdc4',
            number: '#ffe66d',
            odd: '#ff9f43',
            even: '#a55eea',
        };

        const createBall = (id: number, char: string, type: Ball['type']): Ball => ({
            id,
            char,
            x: Math.random() * 80 + 5,
            y: Math.random() * 60 + 10,
            dx: (Math.random() - 0.5) * 4,
            dy: (Math.random() - 0.5) * 4,
            type,
            color: colors[type],
        });

        const balls: Ball[] = [];
        let id = 0;

        // Add 3 lowercase
        for (let i = 0; i < 3; i++) {
            const char = lowercaseChars[Math.floor(Math.random() * lowercaseChars.length)];
            balls.push(createBall(id++, char, 'lowercase'));
        }

        // Add 3 uppercase
        for (let i = 0; i < 3; i++) {
            const char = uppercaseChars[Math.floor(Math.random() * uppercaseChars.length)];
            balls.push(createBall(id++, char, 'uppercase'));
        }

        // Add 3 odd numbers
        for (let i = 0; i < 3; i++) {
            const char = oddNumbers[Math.floor(Math.random() * oddNumbers.length)];
            balls.push(createBall(id++, char, 'odd'));
        }

        // Add 3 even numbers
        for (let i = 0; i < 3; i++) {
            const char = evenNumbers[Math.floor(Math.random() * evenNumbers.length)];
            balls.push(createBall(id++, char, 'even'));
        }

        return balls;
    });

    const [challenge] = useState<{ type: Ball['type']; label: string }>(() => {
        const challenges: { type: Ball['type']; label: string }[] = [
            { type: 'lowercase', label: 'lowercase letters (a-z)' },
            { type: 'uppercase', label: 'UPPERCASE letters (A-Z)' },
            { type: 'odd', label: 'odd numbers (1,3,5,7,9)' },
            { type: 'even', label: 'even numbers (0,2,4,6,8)' },
        ];
        return challenges[Math.floor(Math.random() * challenges.length)];
    });

    const [message, setMessage] = useState('');
    const [isSuccess, setIsSuccess] = useState(false);

    // Bounce the balls
    useEffect(() => {
        const interval = setInterval(() => {
            setBalls(prev => prev.map(ball => {
                let newX = ball.x + ball.dx;
                let newY = ball.y + ball.dy;
                let newDx = ball.dx;
                let newDy = ball.dy;

                // Bounce off walls
                if (newX <= 0 || newX >= 90) {
                    newDx *= -1;
                    newX = ball.x + newDx;
                }
                if (newY <= 5 || newY >= 75) {
                    newDy *= -1;
                    newY = ball.y + newDy;
                }

                return { ...ball, x: newX, y: newY, dx: newDx, dy: newDy };
            }));
        }, 30);
        return () => clearInterval(interval);
    }, []);

    // Check if target balls are aligned horizontally
    const checkAlignment = useCallback(() => {
        const targetBalls = balls.filter(b => b.type === challenge.type);
        if (targetBalls.length < 2) return false;

        const yPositions = targetBalls.map(b => b.y);
        const minY = Math.min(...yPositions);
        const maxY = Math.max(...yPositions);
        const tolerance = 6; // Stricter - all balls must be within 6% of each other

        return (maxY - minY) < tolerance;
    }, [balls, challenge.type]);

    const handleSubmit = () => {
        if (checkAlignment()) {
            setIsSuccess(true);
            // Show congratulations popup and reload after
            setTimeout(() => {
                alert("🎉 CONGRATULATIONS! 🎉\n\nYou actually aligned them!\nAre you a wizard?!\n\nClick OK to try again...");
                window.location.reload();
            }, 100);
        } else {
            setMessage("❌ NOT ALIGNED! The balls must be in a horizontal line. Keep watching...");
            setIsSuccess(false);
            setTimeout(() => setMessage(''), 2500);
        }
    };

    // Get target balls for highlighting
    const targetBalls = balls.filter(b => b.type === challenge.type);
    const isCurrentlyAligned = checkAlignment();

    return (
        <div style={{
            minHeight: '100vh',
            background: 'linear-gradient(135deg, #1a1a2e 0%, #16213e 50%, #0f3460 100%)',
            display: 'flex',
            flexDirection: 'column',
            alignItems: 'center',
            fontFamily: 'Comic Sans MS, cursive',
            overflow: 'hidden',
            position: 'relative',
            padding: '10px',
            boxSizing: 'border-box',
        }}>
            <h1 style={{ 
                color: '#e94560', 
                textShadow: '2px 2px #533483',
                margin: '5px 0',
                fontSize: '1.5rem',
                textAlign: 'center',
            }}>
                🎱 Bouncing Ball CAPTCHA 🎱
            </h1>

            {/* Legend - compact */}
            <div style={{
                display: 'flex',
                gap: '10px',
                flexWrap: 'wrap',
                justifyContent: 'center',
                margin: '5px 0',
                padding: '8px 15px',
                background: 'rgba(0,0,0,0.3)',
                borderRadius: '10px',
            }}>
                {[
                    { type: 'lowercase', color: '#ff6b6b', label: 'a-z' },
                    { type: 'uppercase', color: '#4ecdc4', label: 'A-Z' },
                    { type: 'odd', color: '#ff9f43', label: 'Odd' },
                    { type: 'even', color: '#a55eea', label: 'Even' },
                ].map(item => (
                    <div key={item.type} style={{
                        display: 'flex',
                        alignItems: 'center',
                        gap: '5px',
                        opacity: item.type === challenge.type ? 1 : 0.4,
                        padding: '3px 8px',
                        borderRadius: '8px',
                        background: item.type === challenge.type ? 'rgba(255,255,255,0.1)' : 'transparent',
                        border: item.type === challenge.type ? '2px solid white' : '2px solid transparent',
                    }}>
                        <div style={{
                            width: '18px',
                            height: '18px',
                            borderRadius: '50%',
                            background: item.color,
                        }} />
                        <span style={{ color: 'white', fontSize: '0.8rem', fontWeight: item.type === challenge.type ? 'bold' : 'normal' }}>
                            {item.label}
                        </span>
                    </div>
                ))}
            </div>
            
            <p style={{ 
                color: '#fff', 
                fontSize: '1rem',
                margin: '5px 0',
                textAlign: 'center',
            }}>
                Align all <span style={{ color: targetBalls[0]?.color, fontWeight: 'bold' }}>
                    {challenge.label}
                </span> horizontally!
            </p>

            {/* Alignment indicator */}
            <div style={{
                padding: '6px 15px',
                borderRadius: '15px',
                background: isCurrentlyAligned ? '#00ff00' : '#ff0000',
                color: 'black',
                fontWeight: 'bold',
                marginBottom: '8px',
                fontSize: '0.9rem',
                transition: 'background 0.2s',
            }}>
                {isCurrentlyAligned ? '✅ ALIGNED! CLICK SUBMIT!' : '⏳ Waiting...'}
            </div>

            {/* Ball container */}
            <div style={{
                position: 'relative',
                width: '95%',
                height: '40vh',
                background: 'rgba(0,0,0,0.5)',
                borderRadius: '15px',
                border: '3px solid #e94560',
                overflow: 'hidden',
            }}>
                {/* Horizontal guide line */}
                {targetBalls.length > 0 && (
                    <div style={{
                        position: 'absolute',
                        left: 0,
                        right: 0,
                        top: `${targetBalls.reduce((sum, b) => sum + b.y, 0) / targetBalls.length}%`,
                        height: '2px',
                        background: isCurrentlyAligned ? 'rgba(0,255,0,0.5)' : 'rgba(255,255,255,0.2)',
                        transition: 'top 0.1s',
                    }} />
                )}

                {/* Bouncing balls */}
                {balls.map(ball => (
                    <div
                        key={ball.id}
                        style={{
                            position: 'absolute',
                            left: `${ball.x}%`,
                            top: `${ball.y}%`,
                            width: '50px',
                            height: '50px',
                            borderRadius: '50%',
                            background: `radial-gradient(circle at 30% 30%, ${ball.color}, ${ball.color}88)`,
                            display: 'flex',
                            alignItems: 'center',
                            justifyContent: 'center',
                            fontSize: '1.5rem',
                            fontWeight: 'bold',
                            color: '#000',
                            boxShadow: ball.type === challenge.type
                                ? `0 0 20px ${ball.color}, 0 0 40px ${ball.color}`
                                : '2px 2px 10px rgba(0,0,0,0.5)',
                            border: ball.type === challenge.type ? '3px solid white' : 'none',
                            transform: 'translate(-50%, -50%)',
                            transition: 'left 0.03s linear, top 0.03s linear',
                        }}
                    >
                        {ball.char}
                    </div>
                ))}
            </div>

            {/* Submit Button - fixed position */}
            <div style={{ display: 'flex', gap: '15px', marginTop: '15px' }}>
                <button
                    onClick={handleSubmit}
                    style={{
                        padding: '12px 40px',
                        fontSize: '1.3rem',
                        background: isCurrentlyAligned
                            ? 'linear-gradient(45deg, #00ff00, #00cc00)'
                            : 'linear-gradient(45deg, #e94560, #533483)',
                        color: 'white',
                        border: 'none',
                        borderRadius: '25px',
                        cursor: 'pointer',
                        boxShadow: isCurrentlyAligned
                            ? '0 0 20px #00ff00'
                            : '0 4px 15px rgba(0,0,0,0.3)',
                        transition: 'all 0.3s',
                        fontWeight: 'bold',
                    }}
                >
                    🚀 SUBMIT
                </button>

                <button
                    onClick={() => window.location.reload()}
                    style={{
                        padding: '12px 25px',
                        fontSize: '1.1rem',
                        background: 'linear-gradient(45deg, #667eea, #764ba2)',
                        color: 'white',
                        border: 'none',
                        borderRadius: '25px',
                        cursor: 'pointer',
                        boxShadow: '0 4px 15px rgba(0,0,0,0.3)',
                        fontWeight: 'bold',
                    }}
                >
                    🔄 NEW
                </button>
            </div>

            {/* Message - fixed height area */}
            <div style={{ 
                height: '50px', 
                display: 'flex', 
                alignItems: 'center', 
                justifyContent: 'center',
                marginTop: '8px',
            }}>
                {message && (
                    <div style={{
                        padding: '10px 20px',
                        background: 'rgba(255,0,0,0.2)',
                        color: '#ff6b6b',
                        fontSize: '1rem',
                        borderRadius: '10px',
                        border: '2px solid #ff0000',
                        fontWeight: 'bold',
                    }}>
                        {message}
                    </div>
                )}
            </div>
        </div>
    );
};

export default WorstCaptcha;